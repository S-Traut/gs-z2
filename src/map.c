#include <map.h>

ZII_graphics_tilemap ZII_tilemap_init()
{
  size_t vbo_size = 0;
  float *vbo_data = ZII_generate_map_vertex_buffer(&vbo_size);

  gs_graphics_vertex_buffer_desc_t vbo_desc = {
      .data = vbo_data,
      .size = vbo_size,
  };
  gs_handle(gs_graphics_vertex_buffer_t) vbo = gs_graphics_vertex_buffer_create(&vbo_desc);

  size_t ibo_size = 0;
  int *ibo_data = ZII_generate_map_index_buffer(&ibo_size);
  gs_graphics_index_buffer_desc_t ibo_desc = {
      .data = ibo_data,
      .size = ibo_size,
  };
  gs_handle_gs_graphics_index_buffer_t ibo = gs_graphics_index_buffer_create(&ibo_desc);

  printf("%d\n", ibo_size);

  free(vbo_data);
  free(ibo_data);

  return (ZII_graphics_tilemap){
      .vbo = vbo,
      .ibo = ibo,
  };
}

gs_vec2 ZII_get_tile_texture_coords(int x, int y)
{
  return (gs_vec2){.x = 0.0f, .y = 0.0f};
}

float *ZII_generate_map_vertex_buffer(size_t *size)
{
  float *vertex_data = malloc(sizeof(float) * ((10 * 10) * 16));
  int tile_index = 0;
  for (int x = 0; x < 10; x++)
  {
    for (int y = 0; y < 10; y++)
    {
      gs_vec2 t_coords = ZII_get_tile_texture_coords(x, y);
      int offset = tile_index * 16;

      // TL
      vertex_data[offset + 0] = x;
      vertex_data[offset + 1] = y;
      vertex_data[offset + 2] = t_coords.x;
      vertex_data[offset + 3] = t_coords.y;
      offset += 4;

      // TR
      vertex_data[offset + 0] = x + 1.0f;
      vertex_data[offset + 1] = y;
      vertex_data[offset + 2] = t_coords.x;
      vertex_data[offset + 3] = t_coords.y;
      offset += 4;

      // BL
      vertex_data[offset + 0] = x;
      vertex_data[offset + 1] = y + 1.0f;
      vertex_data[offset + 2] = t_coords.x;
      vertex_data[offset + 3] = t_coords.y;
      offset += 4;

      // BR
      vertex_data[offset + 0] = x + 1.0f;
      vertex_data[offset + 1] = y + 1.0f;
      vertex_data[offset + 2] = t_coords.x;
      vertex_data[offset + 3] = t_coords.y;

      tile_index++;
      *size += sizeof(float) * 16;
    }
  }

  return vertex_data;
}

int *ZII_generate_map_index_buffer(size_t *size)
{
  int *index_buffer = malloc(sizeof(int) * ((10 * 10) * 6));
  int index = 0;
  for (int x = 0; x < 10; x++)
  {
    for (int y = 0; y < 10; y++)
    {
      int offset = index * 6;
      int vertice_offset = index * 4;
      index_buffer[offset + 0] = vertice_offset + 0;
      index_buffer[offset + 1] = vertice_offset + 2;
      index_buffer[offset + 2] = vertice_offset + 1;
      index_buffer[offset + 3] = vertice_offset + 1;
      index_buffer[offset + 4] = vertice_offset + 2;
      index_buffer[offset + 5] = vertice_offset + 3;
      *size += sizeof(int) * 6;
      index++;
    }
  }
  return index_buffer;
}