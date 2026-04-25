#include "stdafx.h"
#include "../xrRender/ResourceManager.h"
#include "../xrRender/dxRenderDeviceRender.h"
#include "dx10TextureUtils.h"

CRT::CRT()
{
	pSurface = NULL;
	pRT = NULL;
	pZRT = NULL;
	dwWidth = 0;
	dwHeight = 0;
	fmt = D3DFMT_UNKNOWN;
}

CRT::~CRT()
{
	destroy();

	// release external reference
	DEV->_DeleteRT(this);
}

void CRT::create(LPCSTR Name, u32 w, u32 h,	D3DFORMAT f, u32 SampleCount)
{
	if (pSurface)
		return;

	R_ASSERT(HW.pDevice && Name && Name[0] && w && h);
	_order = CPU::GetCLK();

	dwWidth = w;
	dwHeight = h;
	fmt = f;

	// Check width-and-height of render target surface
	if (w > D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION)
		return;

	if (h > D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION)
		return;

	// Select usage
	u32 usage = 0;
	if (D3DFMT_D24X8 == fmt)
		usage = D3DUSAGE_DEPTHSTENCIL;
	else if (D3DFMT_D24S8 == fmt)
		usage = D3DUSAGE_DEPTHSTENCIL;
	else if (D3DFMT_D15S1 == fmt)
		usage = D3DUSAGE_DEPTHSTENCIL;
	else if (D3DFMT_D16 == fmt)	
		usage = D3DUSAGE_DEPTHSTENCIL;
	else if (D3DFMT_D16_LOCKABLE == fmt)
		usage = D3DUSAGE_DEPTHSTENCIL;
	else if (D3DFMT_D32F_LOCKABLE == fmt)
		usage = D3DUSAGE_DEPTHSTENCIL;
	else if ((D3DFORMAT)MAKEFOURCC('D', 'F', '2', '4') == fmt)
		usage = D3DUSAGE_DEPTHSTENCIL;
	else
		usage = D3DUSAGE_RENDERTARGET;

	DXGI_FORMAT dx10FMT;
   
	if (fmt != D3DFMT_D24S8)
		dx10FMT = dx10TextureUtils::ConvertTextureFormat(fmt);
	else
	{
		dx10FMT = DXGI_FORMAT_R24G8_TYPELESS;
		usage = D3DUSAGE_DEPTHSTENCIL;
	}

	bool bUseAsDepth = (usage == D3DUSAGE_RENDERTARGET) ? false : true;

	// Try to create texture/surface
	DEV->Evict();
	// Create the render target texture
	D3D10_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = dwWidth;
	desc.Height = dwHeight;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = dx10FMT;
	desc.SampleDesc.Count = SampleCount;
	desc.Usage = D3D10_USAGE_DEFAULT;
	if (SampleCount <= 1)
	   desc.BindFlags = D3D10_BIND_SHADER_RESOURCE | (bUseAsDepth ? D3D10_BIND_DEPTH_STENCIL : D3D10_BIND_RENDER_TARGET);
	else
	{
		desc.BindFlags = (bUseAsDepth ? D3D10_BIND_DEPTH_STENCIL : (D3D10_BIND_SHADER_RESOURCE | D3D10_BIND_RENDER_TARGET));
		if (RImplementation.o.dx10_msaa_opt)
		{
			desc.SampleDesc.Quality = UINT(D3D10_STANDARD_MULTISAMPLE_PATTERN);
		}
	}

	CHK_DX(HW.pDevice->CreateTexture2D(&desc, NULL, &pSurface));
	// OK
#ifdef DEBUG
	Msg("* created RT(%s), %dx%d, format = %d samples = %d", Name, w, h, dx10FMT, SampleCount);
#endif // DEBUG

	if (bUseAsDepth)
	{
		D3D10_DEPTH_STENCIL_VIEW_DESC ViewDesc;
		ViewDesc.Format = DXGI_FORMAT_UNKNOWN;
		if (SampleCount <= 1)
		{
			ViewDesc.ViewDimension = D3D10_DSV_DIMENSION_TEXTURE2D;
		}
		else
		{
			ViewDesc.ViewDimension = D3D10_DSV_DIMENSION_TEXTURE2DMS;
			ViewDesc.Texture2DMS.UnusedField_NothingToDefine = 0;
		}

		ViewDesc.Texture2D.MipSlice = 0;
		switch (desc.Format)
		{
		case DXGI_FORMAT_R24G8_TYPELESS:
			ViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
			break;
		case DXGI_FORMAT_R32_TYPELESS:
			ViewDesc.Format = DXGI_FORMAT_D32_FLOAT;
			break;
		}

		CHK_DX(HW.pDevice->CreateDepthStencilView(pSurface, &ViewDesc, &pZRT));
	}
	else
		CHK_DX(HW.pDevice->CreateRenderTargetView(pSurface, 0, &pRT));

	pTexture = DEV->_CreateTexture(Name);
	pTexture->surface_set(pSurface);
}

void CRT::destroy()
{
	if (pTexture._get())	
	{
		pTexture->surface_set(0);
		pTexture.destroy();
		pTexture = nullptr;
	}
	_RELEASE(pRT);
	_RELEASE(pZRT);
	_RELEASE(pSurface);
}

void CRT::reset_begin()
{
	destroy();
}

void CRT::reset_end()
{
	create(*cName, dwWidth, dwHeight, fmt);
}

void resptrcode_crt::create(LPCSTR Name, u32 w, u32 h, D3DFORMAT f, u32 SampleCount)
{
	_set(DEV->_CreateRT(Name, w, h, f, SampleCount));
}
