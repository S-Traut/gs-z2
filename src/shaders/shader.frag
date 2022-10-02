#version 460
 
out vec4 FragColor;

in vec2 TexCoord;
in vec3 OutColor;

uniform sampler2D u_tex;

void main()
{
  FragColor = texture(u_tex, TexCoord); 

};