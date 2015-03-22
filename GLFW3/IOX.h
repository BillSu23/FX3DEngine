#pragma once
#include <vector>
using std::vector;
#include <GL\glfw3.h>

class IOX
{
	vector<void (*)(GLFWwindow *, int, int, int, int)> keyCallBackVec;
	vector<void (*)(GLFWwindow *, double, double)> mouseMovesCBVec;
	unsigned cbidx;

	IOX() : keyCallBackVec(), mouseMovesCBVec(), cbidx(0)
	{

	}
public:
	void registerKeyCBFuncs(void (*CB)(GLFWwindow* , int , int , int , int))
	{//���дvoid CB(GLFWwindow*, int, int, int, int)��vectorһ��ʹ����ô�ͻ����ԭ��Ӧ������Ϊ�������ͺ���ָ�뻹���������,�����ָ��������vector�����ǲ��Եġ�
		keyCallBackVec.push_back(CB);
	}

	void registerMouseMoveFuncs(void (*CB)(GLFWwindow *, double , double))
	{
		mouseMovesCBVec.push_back(CB);
	}	 

	static IOX *getInstance()
	{
		static IOX iox;
		return &iox;
	}

	void keyCB(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		for (unsigned i = 0; i < keyCallBackVec.size(); i++)
		{
			(*keyCallBackVec[i])(window, key, scancode, action, mods);
		}
	}

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		IOX *iox = IOX::getInstance();
		iox->keyCB(window, key, scancode, action, mods);
	}

	static void mouseMoveCallBack(GLFWwindow *w, double x, double y)
	{
		IOX *iox = IOX::getInstance();
		iox->mouseMoveCB(w, x, y);
	}

	void mouseMoveCB(GLFWwindow *w, double x, double y)
	{
		for (unsigned i = 0; i < mouseMovesCBVec.size(); i++)
			mouseMovesCBVec[i](w, x, y);
	}
};