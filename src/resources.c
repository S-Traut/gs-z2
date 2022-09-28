#include <resources.h>

ZII_asset_manager ZII_initialize_assets()
{
  ZII_asset_manager asset_manager = {0};

  // Loading textures
  gs_dyn_array(gs_asset_texture_t) textures = NULL;
  gs_dyn_array_push(textures, ZII_load_game_textures());
  asset_manager.textures = textures;
  return asset_manager;
}

gs_asset_texture_t ZII_load_game_textures()
{
  const char *texture_file = "assets/game_atlas.png";
  int w, h, c;
  void *tex_data;
  gs_util_load_texture_data_from_file("assets/texture.png", &w, &h, &c, &tex_data, 1);
  gs_graphics_texture_desc_t texture_desc = {
      .data = tex_data,
      .width = w,
      .height = h,
      .format = GS_GRAPHICS_TEXTURE_FORMAT_RGBA8,
      .min_filter = GS_GRAPHICS_TEXTURE_FILTER_NEAREST,
      .mag_filter = GS_GRAPHICS_TEXTURE_FILTER_NEAREST,
  };

  return (gs_asset_texture_t){
      .desc = texture_desc,
      .hndl = gs_graphics_texture_create(&texture_desc),
  };
}