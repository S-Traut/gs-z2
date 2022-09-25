#version 460
 
out vec4 FragColor;

in vec2 TexCoord;
in vec3 OutColor;

uniform sampler2D u_tex;

void main()
{
  FragColor = vec4(OutColor, 1.0); 

};