#ifndef ZII_resources
#define ZII_resources

#include <gs/gs.h>
#include <map.h>

#define TEXTURE_SHEET_WIDTH 1600
#define TEXTURE_SHEET_HEIGHT 1600

typedef struct ZII_asset_manager
{
  gs_asset_texture_t *textures;
  ZII_graphics_tilemap tilemap;
} ZII_asset_manager;

ZII_asset_manager ZII_initialize_assets();
gs_asset_texture_t ZII_load_game_textures();

#endif