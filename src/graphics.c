#include "include/graphics.h"

gs_graphics_vertex_attribute_desc_t ZII_VERTEX_ATTRIBUTES[] = {
    {
        .format = GS_GRAPHICS_VERTEX_ATTRIBUTE_FLOAT2,
        .name = "a_pos",
    },
    {
        .format = GS_GRAPHICS_VERTEX_ATTRIBUTE_FLOAT2,
        .name = "a_tco",
    },
};

ZII_graphics_t ZII_init_graphics()
{
  ZII_graphics_t graphics;
  graphics.shaders = ZII_create_shaders();
  graphics.cb = gs_command_buffer_new();

  gs_graphics_uniform_desc_t texture_uniform_description = {
      .layout = &(gs_graphics_uniform_layout_desc_t){
          .type = GS_GRAPHICS_UNIFORM_SAMPLER2D,
      },
      .stage = GS_GRAPHICS_SHADER_STAGE_FRAGMENT,
      .name = "u_tex",
  };
  graphics.u_texture = gs_graphics_uniform_create(&texture_uniform_description);

  gs_graphics_uniform_desc_t projection_desc = {
      .layout = &(gs_graphics_uniform_layout_desc_t){
          .type = GS_GRAPHICS_UNIFORM_MAT4,
      },
      .stage = GS_GRAPHICS_SHADER_STAGE_VERTEX,
      .name = "u_proj",
  };
  graphics.u_view_projection = gs_graphics_uniform_create(&projection_desc);

  gs_graphics_pipeline_desc_t pipeline_desc = {
      .raster = {
          .shader = graphics.shaders,
      },
      .layout = {
          .attrs = ZII_VERTEX_ATTRIBUTES,
          .size = sizeof(gs_graphics_vertex_attribute_desc_t) * 2,
      },
  };
  graphics.pipeline = gs_graphics_pipeline_create(&pipeline_desc);

  return graphics;
}