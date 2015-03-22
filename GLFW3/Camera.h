#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <GL\glfw3.h>
#include "XMatrix.h"

class Camera
{
	Camera(GLFWwindow *window);
	Camera();
public:
	//Have to init first before use it.
	static Camera *getInstance()
	{
		static Camera camera;
		return &camera;
	}

	void onKeyboard(GLFWwindow *w, int key, int scancode, int action, int mods);
	static void onKeyboardCallBack(GLFWwindow *w, int key, int scancode, int action, int mods);

	void onMouse(double x, double y);
	static void onMouseCallBack(GLFWwindow *w, double x, double y);

	void onEdgesMover();

	const Vector3f& getPos() const
	{
		return pos;
	}

	const Vector3f& GetTarget() const
	{
		return target;
	}

	const Vector3f& GetUp() const
	{
		return up;
	}

	void init();//optional function
private:	
	void update();

	Vector3f pos;
	Vector3f target;//target is the normalized and transformed view
	Vector3f up;

	float angleH;
	float angleV;

	bool onUpperEdge;
	bool onLowerEdge;
	bool onLeftEdge;
	bool onRightEdge;

	Vector2d mousePos;

	float keyWalkSpeed;
	float mouseRotateSpeed;
	float edgeSpeed;
	int margin;
	
	// Rotate the view vector by the horizontal angle around the vertical axis
	Vector3f verticalAxis;

	//initialized to be Vector3f(1.0f, 0.0f, 0.0f); Why this value? Because we make premised assumption that the initialized position is facing x positive direction, and it is consistent with angleH, then we use angleH to rotate to the correct position. The key is to make correct premised assumptin, so that viewInitPos and angleH are consistent.
	//Ϊʲô������ʼ������Ϊ�ٶ��˳�ʼλ��������x��Ȼ��ͨ��angleHת������Ҫ��λ�á���Ϊ�ٶ��ĳ�ʼλ�ã��涨��֮��Ž�����Ӧ����ת��
	Vector3f viewInitPos;
};

#endif

