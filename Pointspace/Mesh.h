#pragma once
#include <vector>
#include "Vertex.h"

class Mesh
{
public:
	Mesh(std::vector<Vertex> _VertexCollection, std::vector<unsigned int> _IndexCollection, glm::vec3 _Position);
	~Mesh();

	std::vector<Vertex> VertexCollection;
	std::vector<unsigned int> IndexCollection;

	GLuint VAO = 0, VBO = 0, IBO = 0;
	glm::mat4 ModelMatrix = glm::mat4(1.0f);
	glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
};

