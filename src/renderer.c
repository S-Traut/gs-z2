#include <renderer.h>

void ZII_render_frame(ZII_appdata_t *app)
{
  gs_graphics_clear_desc_t clear_description = (gs_graphics_clear_desc_t){
      .actions = &(gs_graphics_clear_action_t){
          .color = {0.1f, 0.1f, 0.1f, 1.f},
      },
  };
  gs_vec2 fs = gs_platform_framebuffer_sizev(gs_platform_main_window());
  gs_mat4 vp = gs_camera_get_view_projection(&app->camera, (int32_t)fs.x, (int32_t)fs.y);

  gs_graphics_bind_uniform_desc_t uniforms[] = {
      {
          .uniform = app->graphics.u_texture,
          .data = &app->graphics.texture,
          .binding = 0,
      },
      {
          .uniform = app->graphics.u_view_projection,
          .data = &vp,
          .binding = 1,
      },
  };

  ZII_graphics_tilemap tilemap = app->tilemap;
  gs_graphics_bind_desc_t binds = {
      .vertex_buffers = {
          &(gs_graphics_bind_vertex_buffer_desc_t){
              .buffer = tilemap.vbo,
          },
      },
      .index_buffers = {
          &(gs_graphics_bind_index_buffer_desc_t){
              .buffer = tilemap.ibo,
          },
      },
      .uniforms = {
          .desc = uniforms,
          .size = sizeof(uniforms),
      },
  };

  float viewx = fs.x;
  float viewy = fs.x * 9 / 16;
  float viewox = 0;
  float viewoy = (fs.y - viewy) / 2;
  if (viewy > fs.y)
  {
    viewx = fs.y * 16 / 9;
    viewy = fs.y;
    viewox = (fs.x - viewx) / 2;
    viewoy = 0;
  }

  gs_command_buffer_t *cb = &app->graphics.cb;

  gs_graphics_begin_render_pass(cb, GS_GRAPHICS_RENDER_PASS_DEFAULT);
  gs_graphics_set_viewport(cb, 0, 0, (int32_t)fs.x, (int32_t)fs.y);
  gs_graphics_clear(cb, &clear_description);
  gs_graphics_draw_desc_t draw_desc = {.start = 0, .count = 6500};
  gs_graphics_bind_pipeline(cb, app->graphics.pipeline);
  gs_graphics_apply_bindings(cb, &binds);
  gs_graphics_draw(cb, &draw_desc);
  gs_graphics_end_render_pass(cb);

  gs_graphics_submit_command_buffer(cb);
}