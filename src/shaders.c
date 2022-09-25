#include <shaders.h>

gs_shader ZII_create_shaders()
{
  char *v_src = gs_platform_read_file_contents("src/shaders/shader.vert", "rb", 0);
  char *f_src = gs_platform_read_file_contents("src/shaders/shader.frag", "rb", 0);

  gs_graphics_shader_desc_t shader_desc = {
      .name = "triangle",
      .size = 2 * sizeof(gs_graphics_shader_source_desc_t),
      .sources = (gs_graphics_shader_source_desc_t[]){
          {.type = GS_GRAPHICS_SHADER_STAGE_VERTEX, .source = v_src},
          {.type = GS_GRAPHICS_SHADER_STAGE_FRAGMENT, .source = f_src},
      },
  };

  return gs_graphics_shader_create(&shader_desc);
}