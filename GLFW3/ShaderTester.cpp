#include "ShaderTester.h"
#include "Geometries.h"
#include "ShaderManager.h"

namespace ShaderTestName
{
	const char* pVs = "ShaderFiles/shader.vs";
	const char* pFs = "ShaderFiles/shader.fs";
}

ShaderTester::ShaderTester()
{
	mGlfwInit();
	genGeometry();
	initShader();
}

ShaderTester::~ShaderTester()
{
}

void ShaderTester::initShader()
{
	using namespace ShaderTestName;
	ShaderManager *shm = ShaderManager::getInstance();
	shm->addVertexShader(pVs);
	shm->addFragmentShader(pFs);
	shm->createShaderProgram();
}

void ShaderTester::genGeometry()
{
	using namespace GEO_PUBLIC_PARA;
	GeometryFactory *geo = GeometryFactory::getInstance();
	Vector3f *vers = geo->genGeometry(GEOMATRIES::HEART_1);
	gSegments = segments;
	//genHeart_2(vers, 0, segments, 0.f, 0.f, 0.02);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//���ʹ��Vector3f vers[360]�����������ڴ棬��ô����Ϳ���ʹ��sizeof(vers), vers�������ò������������ʹ�ö�̬�ڴ棬��ô����Ͳ���ʹ��sizeof(vers)��ֻ��ʹ��segments*sizeof(Vector3f)�������ֶ����úô�С��
	glBufferData(GL_ARRAY_BUFFER, segments*sizeof(Vector3f), vers, GL_STATIC_DRAW);
}

void ShaderTester::run()
{
	while (!glfwWindowShouldClose(window))
	{
		//viewProject();

		draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	terminate();
}

void ShaderTester::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POLYGON, 0, gSegments);

	glDisableVertexAttribArray(0);
}