#ifndef ZII_GRAPHICS
#define ZII_GRAPHICS

#include <gs/gs.h>
#include <shaders.h>

typedef struct ZII_graphics_t
{
  gs_command_buffer_t cb;
  gs_handle(gs_graphics_shader_t) shaders;
  gs_handle(gs_graphics_uniform_t) u_texture;
  gs_handle(gs_graphics_uniform_t) u_view_projection;
  gs_handle(gs_graphics_pipeline_t) pipeline;
  gs_handle(gs_graphics_texture_t) texture;
} ZII_graphics_t;

ZII_graphics_t ZII_init_graphics();
gs_graphics_clear_desc_t ZII_clear();

#endif