#version 330

out vec4 color;
in vec4 fragColor;

void main()
{
	color = vec4(fragColor);
}