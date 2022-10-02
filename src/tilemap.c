#include <tilemap.h>
#include <resources.h>

ZII_graphics_tilemap ZII_tilemap_init()
{
  ZII_graphics_tilemap tilemap;

  // Load tilemap from the text file.
  size_t filesize;
  char *file = gs_read_file_contents_into_string_null_term("src/data/tilemap.txt", "r", &filesize);
  size_t tile_count = 0;
  tilemap.tiles = ZII_generate_tiles(file, filesize, &tile_count);
  tilemap.tile_count = tile_count;

  size_t vbo_size = 0;
  float *vbo_data = ZII_generate_map_vertex_buffer(&vbo_size, tilemap);

  gs_graphics_vertex_buffer_desc_t vbo_desc = {
      .data = vbo_data,
      .size = vbo_size,
  };
  tilemap.vbo = gs_graphics_vertex_buffer_create(&vbo_desc);

  size_t ibo_size = 0;
  int *ibo_data = ZII_generate_map_index_buffer(&ibo_size, tilemap);

  gs_graphics_index_buffer_desc_t ibo_desc = {
      .data = ibo_data,
      .size = ibo_size,
  };
  tilemap.ibo = gs_graphics_index_buffer_create(&ibo_desc);

  free(vbo_data);
  free(ibo_data);

  return tilemap;
}

ZII_tilemap_tile *ZII_generate_tiles(char *file, size_t filesize, size_t *tile_count)
{
  size_t t_count = ZII_get_tilemap_size(file, filesize);
  ZII_tilemap_tile *tiles = malloc(sizeof(ZII_tilemap_tile) * t_count);
  int64_t tile_index = 0, x = 0, y = 0;
  for (int i = 0; i < filesize; i++)
  {
    if (file[i] == '\n')
    {
      y--;
      x = 0;
      continue;
    }

    ZII_tilemap_tile tile = {
        .x = x,
        .y = y,
        .type = file[i],
    };

    memcpy(tiles + tile_index, &tile, sizeof(ZII_tilemap_tile));
    tile_index++;
    x++;
  }
  *tile_count = t_count;
  return tiles;
}

gs_vec2 ZII_get_tile_texture_coords(char tile_type)
{
  size_t texture_id = (int)(tile_type - 46);
  float x = (texture_id * TEXTURE_TILE_WIDTH) / TEXTURE_SHEET_WIDTH;
  float y = 0;
  return (gs_vec2){.x = x, .y = y};
}

size_t ZII_get_tilemap_size(char *file_content, size_t filesize)
{
  size_t sum = 0;
  for (int i = 0; i < filesize; i++)
  {
    if (file_content[i] != '\n')
      sum++;
  }
  return sum;
}

float *ZII_generate_map_vertex_buffer(size_t *size, ZII_graphics_tilemap tilemap)
{
  size_t tilemap_size = tilemap.tile_count * 16;
  *size = sizeof(float) * tilemap_size;
  float *vertex_data = malloc(*size);

  float x = 0.0f, y = 0.0f;
  for (int i = 0; i < tilemap.tile_count; i++)
  {
    float tile_data[4][4];
    ZII_tilemap_tile tile = tilemap.tiles[i];
    gs_vec2 t_coords = ZII_get_tile_texture_coords(tile.type);

    // TOP LEFT
    tile_data[0][0] = tile.x;
    tile_data[0][1] = tile.y;
    tile_data[0][2] = t_coords.x;
    tile_data[0][3] = t_coords.y + TEXTURE_TILE_HN;

    // TOP RIGHT
    tile_data[1][0] = tile.x + 1;
    tile_data[1][1] = tile.y;
    tile_data[1][2] = t_coords.x + TEXTURE_TILE_WN;
    tile_data[1][3] = t_coords.y + TEXTURE_TILE_HN;

    // BOTTOM LEFT
    tile_data[2][0] = tile.x;
    tile_data[2][1] = tile.y + 1;
    tile_data[2][2] = t_coords.x;
    tile_data[2][3] = t_coords.y;

    // BOTTOM RIGHT
    tile_data[3][0] = tile.x + 1;
    tile_data[3][1] = tile.y + 1;
    tile_data[3][2] = t_coords.x + TEXTURE_TILE_WN;
    tile_data[3][3] = t_coords.y;

    memcpy(vertex_data + i * 16, tile_data, sizeof(float) * 16);
  }
  return vertex_data;
}

int *ZII_generate_map_index_buffer(size_t *size, ZII_graphics_tilemap tilemap)
{
  *size = sizeof(int) * (tilemap.tile_count * 6);
  int *index_buffer = malloc(*size);

  for (int i = 0; i < tilemap.tile_count; i++)
  {
    int tile_data[6];
    int v_offset = i * 4;

    tile_data[0] = v_offset + 0;
    tile_data[1] = v_offset + 1;
    tile_data[2] = v_offset + 2;
    tile_data[3] = v_offset + 2;
    tile_data[4] = v_offset + 3;
    tile_data[5] = v_offset + 1;

    memcpy(index_buffer + i * 6, tile_data, sizeof(int) * 6);
  }
  return index_buffer;
}