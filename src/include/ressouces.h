#ifndef ZII_RESSOURCES
#define ZII_RESSOURCES

#include <gs/gs.h>
#include <map.h>

typedef struct ZII_asset_manager
{
  gs_asset_texture_t *textures;
  ZII_graphics_tilemap tilemap;
} ZII_asset_manager;

void ZII_initialize_assets();
gs_asset_texture_t ZII_load_game_textures();

#endif