#include <resources.h>

ZII_asset_manager ZII_initialize_assets()
{
  // (TODO) Asset management system
  ZII_asset_manager asset_manager = {0};
  return asset_manager;
}

gs_handle_gs_graphics_texture_t ZII_load_game_textures()
{
  const char *texture_file = "assets/game_atlas.png";
  int w, h, c;
  void *tex_data;
  gs_util_load_texture_data_from_file("assets/game_atlas.jpg", &w, &h, &c, &tex_data, 0);
  gs_graphics_texture_desc_t texture_desc = {
      .data = tex_data,
      .width = w,
      .height = h,
      .format = GS_GRAPHICS_TEXTURE_FORMAT_RGBA8,
      .min_filter = GS_GRAPHICS_TEXTURE_FILTER_NEAREST,
      .mag_filter = GS_GRAPHICS_TEXTURE_FILTER_NEAREST,
  };

  return gs_graphics_texture_create(&texture_desc);
}