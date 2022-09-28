#ifndef ZII_CORE
#define ZII_CORE

#include <gs/gs.h>
#include <graphics.h>
#include <map.h>
#include <resources.h>

typedef struct ZII_appdata_t
{
  ZII_graphics_t graphics;
  ZII_graphics_tilemap tilemap;
  ZII_asset_manager assets;
  gs_camera_t camera;
} ZII_appdata_t;

void init();
void loop();

#endif