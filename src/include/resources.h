#ifndef ZII_resources
#define ZII_resources

#include <gs/gs.h>
#include <tilemap.h>

#define TEXTURE_SHEET_WIDTH 1600.0f
#define TEXTURE_SHEET_HEIGHT 1600.0f
#define TEXTURE_TILE_WIDTH 16.0f
#define TEXTURE_TILE_HEIGHT 16.0f
#define TEXTURE_TILE_WN TEXTURE_TILE_WIDTH / TEXTURE_SHEET_WIDTH
#define TEXTURE_TILE_HN TEXTURE_TILE_HEIGHT / TEXTURE_SHEET_HEIGHT

typedef struct ZII_asset_manager
{
  gs_asset_texture_t *textures;
} ZII_asset_manager;

ZII_asset_manager ZII_initialize_assets();
gs_handle_gs_graphics_texture_t ZII_load_game_textures();
#endif