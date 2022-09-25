#ifndef ZII_MAP
#define ZII_MAP

#include <gs/gs.h>

typedef struct ZII_graphics_tilemap
{
  gs_handle_gs_graphics_vertex_buffer_t vbo;
  gs_handle_gs_graphics_index_buffer_t ibo;
} ZII_graphics_tilemap;

ZII_graphics_tilemap ZII_tilemap_init();

float *ZII_generate_map_vertex_buffer(size_t *size);

int *ZII_generate_map_index_buffer(size_t *size);

gs_vec2 ZII_get_tile_texture_coords(int x, int y);

#endif