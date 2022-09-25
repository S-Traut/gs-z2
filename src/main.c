#include <gs/gs.h>
#include <core.h>

ZII_appdata_t *game_data = {0};

gs_app_desc_t gs_main(int32_t argc, char **argv)
{
  return (gs_app_desc_t){
      .init = init,
      .update = loop,
      .window_title = "GST ZELDA II",
      .user_data = &game_data,
  };
}
