#pragma once
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <time.h>

#include "Camera.h"
#include "Skybox.h"
#include "Light.h"
#include "Timestep.h"

#include "TerrainGen.h"
#include "WaterGen.h"
#include "CloudGen.h"
#include "TreeGen.h"
#include "GrassGen.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Init(
		const char* _Title,
		const int _Width,
		const int _Height);
	void OnUpdate();
	void Terminate();

	GLFWwindow* m_Window = NULL;

	TerrainGen* m_TerrainGen = NULL;
	WaterGen* m_WaterGen = NULL;
	CloudGen* m_CloudGen = NULL;
	TreeGen* m_TreeGen = NULL;
	GrassGen* m_GrassGen = NULL;

	Skybox* m_Skybox = NULL;
	Camera* m_Camera = NULL;
	Light* m_DirLight = NULL;

	double m_CursorPosX, m_CursorPosY;
	float m_LastFrameTime = 0.0f;

	const int m_HW_GeoSetOutputComp = 4;
	int m_HW_GeoMaxOutputComp;
	int m_HW_MaxGeoVertexCount;
	int m_HW_MaxTessVertsPerPatch;
};

