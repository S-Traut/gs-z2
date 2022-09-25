#include <controls.h>
#include <camera.h>

void ZII_process_controls(ZII_appdata_t *app)
{
  if (gs_platform_key_pressed(GS_KEYCODE_ESC))
    gs_quit();

  ZII_camera_controls(&app->camera);
}