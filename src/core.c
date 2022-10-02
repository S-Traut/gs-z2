#include <graphics.h>
#include <core.h>
#include <tilemap.h>
#include <controls.h>
#include <renderer.h>
#include <resources.h>

void init()
{
  printf("Welcome to ZII!\n\n");
  ZII_appdata_t *appdata = gs_user_data(ZII_appdata_t);
  appdata->graphics = ZII_init_graphics();
  appdata->camera = gs_camera_default();
  appdata->graphics.texture = ZII_load_game_textures();
  appdata->tilemap = ZII_tilemap_init();
}

void loop()
{
  ZII_appdata_t *appdata = gs_user_data(ZII_appdata_t);
  ZII_process_controls(appdata);
  ZII_render_frame(appdata);
}

void shutdown()
{
}