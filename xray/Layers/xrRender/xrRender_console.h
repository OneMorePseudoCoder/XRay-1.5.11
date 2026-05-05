#pragma once

// Common 
extern ENGINE_API int ps_r__Supersample;
extern ECORE_API int ps_r__LightSleepFrames;

extern ECORE_API float ps_r__Detail_l_ambient;
extern ECORE_API float ps_r__Detail_l_aniso;
extern ECORE_API float ps_r__Detail_density;
				 	   
extern ECORE_API float ps_r__Tree_w_rot;
extern ECORE_API float ps_r__Tree_w_speed;
extern ECORE_API float ps_r__Tree_w_amp;
extern ECORE_API float ps_r__Tree_SBC;		// scale bias correct
extern ECORE_API Fvector ps_r__Tree_Wave;

extern ECORE_API float ps_r__WallmarkTTL;
extern ECORE_API float ps_r__WallmarkSHIFT;
extern ECORE_API float ps_r__WallmarkSHIFT_V;
					   
extern ECORE_API float ps_r__GLOD_ssa_start;
extern ECORE_API float ps_r__GLOD_ssa_end;
extern ECORE_API float ps_r__LOD;
extern ECORE_API float ps_r__ssaDISCARD;
extern ECORE_API float ps_r__ssaDONTSORT;
extern ECORE_API float ps_r__ssaHZBvsTEX;
extern ECORE_API int ps_r__tf_Anisotropic;
extern ECORE_API float ps_r__ssaLOD_A;
extern ECORE_API float ps_r__ssaLOD_B;
extern ECORE_API float ps_r__tf_Mipbias;

extern ECORE_API int ps_r__detail_radius;

extern ECORE_API int opt_static;
extern ECORE_API int opt_dynamic;
extern ECORE_API float ps_r__opt_dist;

enum
{
	RFLAG_BLOODMARKS = (1 << 0),
	RFLAG_ACTOR_SHADOW = (1 << 1),
    // ZergO: new flags
    RFLAG_GLOWS = (1 << 2),
    RFLAF_OPT_GEOM = (1 << 3),
};
extern ECORE_API Flags32 ps_common_flags;

// R1
extern ECORE_API float ps_r1_lmodel_lerp;
extern ECORE_API float ps_r1_dlights_clip;
extern ECORE_API float ps_r1_pps_u;
extern ECORE_API float ps_r1_pps_v;

// R1-specific
extern ECORE_API int ps_r1_GlowsPerFrame;
extern ECORE_API Flags32 ps_r1_flags;

extern ECORE_API float ps_r1_fog_luminance;

enum
{
	R1FLAG_DLIGHTS = (1 << 0),
    R1FLAG_DETAIL_TEXTURES = (2 << 0),
};

// R2-specific
extern ECORE_API Flags32 ps_r2_ls_flags;
extern ECORE_API Flags32 ps_r2_ls_flags_ext;
extern ECORE_API float ps_r2_df_parallax_h;
extern ECORE_API float ps_r2_df_parallax_range;
extern ECORE_API float ps_r2_gmaterial;
extern ECORE_API float ps_r2_tonemap_middlegray;
extern ECORE_API float ps_r2_tonemap_adaptation;
extern ECORE_API float ps_r2_tonemap_low_lum;
extern ECORE_API float ps_r2_tonemap_amount;
extern ECORE_API float ps_r2_ls_bloom_kernel_scale;
extern ECORE_API float ps_r2_ls_bloom_kernel_g;
extern ECORE_API float ps_r2_ls_bloom_kernel_b;
extern ECORE_API float ps_r2_ls_bloom_threshold;
extern ECORE_API float ps_r2_ls_bloom_speed;
extern ECORE_API float ps_r2_ls_dsm_kernel;
extern ECORE_API float ps_r2_ls_psm_kernel;
extern ECORE_API float ps_r2_ls_ssm_kernel;
extern ECORE_API Fvector ps_r2_aa_barier;
extern ECORE_API Fvector ps_r2_aa_weight;
extern ECORE_API float ps_r2_aa_kernel;
extern ECORE_API float ps_r2_mblur;
extern ECORE_API int ps_r2_GI_depth;
extern ECORE_API int ps_r2_GI_photons;
extern ECORE_API float ps_r2_GI_clip;
extern ECORE_API float ps_r2_GI_refl;
extern ECORE_API float ps_r2_ls_depth_scale;
extern ECORE_API float ps_r2_ls_depth_bias;
extern ECORE_API float ps_r2_ls_squality;
extern ECORE_API float ps_r2_sun_near;
extern ECORE_API float ps_r2_sun_near_border;
extern ECORE_API float ps_r2_sun_tsm_projection;
extern ECORE_API float ps_r2_sun_tsm_bias;
extern ECORE_API float ps_r2_sun_depth_far_scale;
extern ECORE_API float ps_r2_sun_depth_far_bias;
extern ECORE_API float ps_r2_sun_depth_near_scale;
extern ECORE_API float ps_r2_sun_depth_near_bias;
extern ECORE_API float ps_r2_sun_lumscale;
extern ECORE_API float ps_r2_sun_lumscale_hemi;
extern ECORE_API float ps_r2_sun_lumscale_amb;
extern ECORE_API float ps_r2_zfill;

extern ECORE_API float ps_r2_dhemi_sky_scale;
extern ECORE_API float ps_r2_dhemi_light_scale;
extern ECORE_API float ps_r2_dhemi_light_flow;
extern ECORE_API int ps_r2_dhemi_count;
extern ECORE_API float ps_r2_slight_fade;
extern ECORE_API int ps_r2_wait_sleep;

//	x - min (0), y - focus (1.4), z - max (100)
extern ECORE_API Fvector3 ps_r2_dof;
extern ECORE_API float ps_r2_dof_sky;
extern ECORE_API float ps_r2_dof_kernel_size;

extern ECORE_API u32 ps_r_sun_shafts;
extern ECORE_API xr_token qsun_shafts_token[];

extern ECORE_API u32 ps_r_ssao;
extern ECORE_API xr_token qssao_token[];

extern ECORE_API u32 ps_r_sun_quality;
extern ECORE_API xr_token qsun_quality_token[];

enum 
{
    R2FLAG_SUN = (1 << 0),
    R2FLAG_DETAILS_SHADOWS = (1 << 1),
    R2FLAG_TONEMAP = (1 << 2),
    R2FLAG_AA = (1 << 3),
    R2FLAG_GI = (1 << 4),
    R2FLAG_FASTBLOOM = (1 << 5),
    R2FLAG_GLOBALMATERIAL = (1 << 6),
    R2FLAG_ZFILL = (1 << 7),
    R2FLAG_R1LIGHTS = (1 << 8),
    R2FLAG_SUN_IGNORE_PORTALS = (1 << 9),

    R2FLAG_DETAIL_BUMP = (1 << 10),

    R2FLAG_EXP_SPLIT_SCENE = (1 << 11),
    R2FLAG_EXP_DONT_TEST_UNSHADOWED = (1 << 12),
    R2FLAG_EXP_DONT_TEST_SHADOWED = (1 << 13),

    R2FLAG_USE_NVDBT = (1 << 14),
    R2FLAG_USE_NVSTENCIL = (1 << 15),

    R2FLAG_EXP_MT_CALC = (1 << 16),

    R2FLAG_SOFT_WATER = (1 << 17), //	Igor: need restart
    R2FLAG_SOFT_PARTICLES = (1 << 18), //	Igor: need restart
    R2FLAG_VOLUMETRIC_LIGHTS = (1 << 19),
    R2FLAG_STEEP_PARALLAX = (1 << 20),
    R2FLAG_DOF = (1 << 21),
    R2FLAG_SUN_ZCULLING = (1 << 22),
    R2FLAG_SUN_FOCUS = (1 << 23),
    R2FLAG_SUN_DETAILS = (1 << 24),
    R2FLAG_SUN_TSM = (1 << 25),
};

enum 
{
    R2FLAGEXT_SSAO_BLUR = (1 << 0),
    R2FLAGEXT_SSAO_OPT_DATA = (1 << 1),
    R2FLAGEXT_SSAO_HALF_DATA = (1 << 2),
    R2FLAGEXT_SSAO_HBAO = (1 << 3),
    R2FLAGEXT_SSAO_HDAO = (1 << 4),
    R2FLAGEXT_SUN_ZCULLING = (1 << 5),
    R2FLAGEXT_SUN_OLD = (1 << 6),
};

// R3
extern ECORE_API Flags32 ps_r3_ls_flags;

extern ECORE_API u32 ps_r3_msaa;
extern ECORE_API xr_token qmsaa_token[];

extern ECORE_API u32 ps_r3_msaa_atest;
extern ECORE_API xr_token qmsaa__atest_token[];

extern ECORE_API u32 ps_r3_minmax_sm;
extern ECORE_API xr_token qminmax_sm_token[];

extern ECORE_API float ps_r3_dyn_wet_surf_near;
extern ECORE_API float ps_r3_dyn_wet_surf_far;
extern ECORE_API int ps_r3_dyn_wet_surf_sm_res;

enum 
{
    R3FLAG_DYN_WET_SURF = (1 << 0),
    R3FLAG_VOLUMETRIC_SMOKE = (1 << 1),
    R3FLAG_MSAA_HYBRID = (1 << 2),
    R3FLAG_MSAA_OPT = (1 << 3),
    R3FLAG_GBUFFER_OPT = (1 << 4),
    R3FLAG_USE_DX10_1 = (1 << 5),
};

extern void xrRender_initconsole();
extern BOOL xrRender_test_hw();