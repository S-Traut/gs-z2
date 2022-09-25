#include <camera.h>

void ZII_camera_controls(gs_camera_t *camera)
{
  // gs_vec2 base_position;
  // if (gs_platform_mouse_pressed(GS_MOUSE_LBUTTON))
  //   drag = true;

  // if (drag)
  // {
  //   gs_vec2 delta = gs_platform_mouse_deltav();
  //   camera->transform.position.x -= delta.x * 0.1;
  //   camera->transform.position.y += delta.y * 0.1;
  // }

  // if (gs_platform_mouse_released(GS_MOUSE_LBUTTON))
  // {
  //   drag = false;
  //   printf("DRAG STOPPED\n");
  // }

  f32 wheel_value_y;
  f32 wheel_value_x;
  gs_platform_mouse_wheel(&wheel_value_x, &wheel_value_y);
  camera->ortho_scale -= wheel_value_y;
}