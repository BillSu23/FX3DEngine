#pragma once
#include <memory>
#include <vector>
#include "XMatrix.h"

//ʹ��һ�������Ϳ��Լ�ס������Ҫ������Shapes�ı���������ʹ��enum�����ƣ���һ��API��û����������һ��
enum GEOMATRIES
{
	HEART_1, HEART_2, CIRCLE, SQURE, RECTANGLE, ELLIPSE, POLYGON, PENTAGON,
	BOX, SHPERE, ELLIPSE3D
};

namespace GEO_PUBLIC_PARA
{
	extern int segments, offset;
	extern float centerX, centerY, radius;
}

void genHeart(Vector3f *vers, int offset, int segments,
		    float ox, float oy, float R = 0.2);

void genHeart_2(Vector3f *&vers, int offset, int segments,
			 float ox, float oy, float R = 0.05);

//base class
class Shape
{
public:
	Shape();
	virtual ~Shape();
};

class Heart_1 : public Shape
{
public:
	Heart_1();
	~Heart_1();
};

class Heart_2 : public Shape
{
public:
	Heart_2();
	~Heart_2();
};

class GeometryFactory
{
	std::vector<std::unique_ptr<Shape> > vpShape;//��ʱ����
	//�Զ������ڴ棬�����ֶ��ͷ�
	std::vector<std::unique_ptr<Vector3f[]> > vpGeoShape;
	GeometryFactory();
public:
	virtual ~GeometryFactory();
	static GeometryFactory *getInstance()
	{
		static GeometryFactory instance;
		return &instance;
	}

	virtual Vector3f *genGeometry(GEOMATRIES geo);

	void genHeart();

	void genHeart_2(Vector3f *vers, int offset, int segments,
		float ox, float oy, float R = 0.05);
};

