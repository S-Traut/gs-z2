#version 460
precision mediump float;
layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_tco;

uniform mat4 u_proj;

out vec2 TexCoord;
out vec3 OutColor;

vec3 colors[] = {
  vec3(1.0, 1.0, 1.0),
  vec3(0.0, 0.0, 0.0),
};

void main() {
    gl_Position = u_proj * vec4(a_pos, 0.0, 1.0);

    OutColor = colors[gl_VertexID % 4];
}

