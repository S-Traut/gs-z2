#ifndef ZII_MAP
#define ZII_MAP

#include <gs/gs.h>

typedef struct ZII_tilemap_tile
{
  int64_t x;
  int64_t y;
  char type;
} ZII_tilemap_tile;

typedef struct ZII_graphics_tilemap
{
  gs_handle_gs_graphics_vertex_buffer_t vbo;
  gs_handle_gs_graphics_index_buffer_t ibo;
  size_t tile_count;
  ZII_tilemap_tile *tiles;
} ZII_graphics_tilemap;

ZII_graphics_tilemap ZII_tilemap_init();

float *ZII_generate_map_vertex_buffer(size_t *size, ZII_graphics_tilemap tilemap);

int *ZII_generate_map_index_buffer(size_t *size, ZII_graphics_tilemap tilemap);

size_t ZII_get_tilemap_size(char *file_content, size_t filesize);

gs_vec2 ZII_get_tile_texture_coords(char tile_type);

ZII_tilemap_tile *ZII_generate_tiles(char *file, size_t filesize, size_t *tile_count);

#endif