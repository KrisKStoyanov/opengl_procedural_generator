#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/type_ptr.hpp>
enum class LightType {
	POINT,
	DIRECTIONAL,
	SPOTLIGHT
};

class Light
{
public:
	Light(
		glm::vec3 _Direction, 
		glm::vec3 _AmbientC, 
		glm::vec3 _DiffuseC, 
		glm::vec3 _SpecularC,
		LightType _Type = LightType::DIRECTIONAL);
	Light(
		glm::vec3 _Position,
		glm::vec3 _AmbientC,
		glm::vec3 _DiffuseC,
		glm::vec3 _SpecularC,
		float _ConstantA,
		float _LinearA,
		float _QuadraticA,
		LightType _Type = LightType::POINT);
	Light(
		glm::vec3 _Position,
		glm::vec3 _Direction,
		glm::vec3 _AmbientC,
		glm::vec3 _DiffuseC,
		glm::vec3 _SpecularC,
		float _ConstantA,
		float _LinearA,
		float _QuadraticA,
		float _CutOff,
		float _OuterCutOff,
		LightType _Type = LightType::SPOTLIGHT);

	Light(
		glm::vec4 _Coords,
		glm::vec4 _AmbientC,
		glm::vec4 _DiffuseC,
		glm::vec4 _SpecularC,
		LightType _Type = LightType::DIRECTIONAL);
	~Light();

	LightType Type;

	glm::vec3 Position;
	glm::vec3 Direction;

	glm::vec4 Coords;
	glm::vec4 AmbientC;
	glm::vec4 DiffuseC;
	glm::vec4 SpecularC;

	float ConstantA;
	float LinearA;
	float QuadraticA;

	float CutOff;
	float OuterCutOff;
};

