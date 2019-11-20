#version 450 core

#define PI 3.14159265359

layout(location = 0) in vec4 VertexCoords;
layout(location = 1) in vec3 VertexNormal;
layout(location = 2) in vec2 VertexUV;

uniform mat4 u_modelMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;
uniform mat3 u_normalMatrix;

uniform float u_time;

out vec4 exCoords;
out vec3 exNormal;
out vec2 exUV;

out float exTime;

void main(void)
{
	exCoords = VertexCoords;
	exNormal = normalize(u_normalMatrix * VertexNormal);
	exUV = VertexUV;
	exTime = u_time;

	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix *
		vec4(VertexCoords.x + sin(VertexCoords.z + u_time), VertexCoords.y - cos(VertexCoords.x + u_time), VertexCoords.z, VertexCoords.w);
}