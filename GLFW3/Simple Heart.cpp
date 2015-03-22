#include "Simple Heart.h"
#include "Geometries.h"

SimpleHeart::SimpleHeart()
{
	mGlfwInit();
	genGeometry();
}

SimpleHeart::~SimpleHeart()
{

}

void SimpleHeart::genGeometry()
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

void SimpleHeart::run()
{
	while (!glfwWindowShouldClose(window))
	{
		viewProject();

		draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	terminate();
}

void SimpleHeart::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//render function
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_LINE_LOOP, 0, gSegments);

	glDisableVertexAttribArray(0);
}