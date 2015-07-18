#include <windows.h>
#include "lib\egl.h"

using namespace egl;

class RenderWindow : public Window
{
private:
public:
	virtual void RenderGLScene(void);
	virtual void OnCreate(WPARAM wParam, LPARAM lParam);
};

void RenderWindow::OnCreate(WPARAM wParam, LPARAM lParam)
{
}

void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	static GLfloat rot=1.0f;
	static GLfloat scale=1.0f,factor=0.01f;
	glTranslatef(-2.0f, 0.0f, -10.0f);

	//5���� �ﰢ�� �̿��ؼ� �������
	glRotatef(rot,0.0f, 0.0f, 1.0f); //��ü ȸ��
	for(int i=1; i<=5; i++)
	{
		glPushMatrix(); 
		glRotatef(72*(i-1), 0.0f, 0.0f, 1.0f); //5������ �߽����� �ﰢ�� ��ġ
		glTranslatef(0.0f, 1.35, 0.0f); //�ﰢ���� ��ħ�� ���� ���ؼ� �ణ �̵�
		glRotatef(i*rot, 1.0f, 0.0f, 0.0f); //����ȸ��
		glBegin(GL_TRIANGLES);
			glVertex3f(-1.0f, 0.0f, 0.0f);
			glVertex3f( 1.0f, 0.0f, 0.0f);
			glVertex3f( 0.0f, 1.0f, 0.0f);
		glEnd();
		glPopMatrix();
	}
	//�𵨺�����ʱ�ȭ
	glLoadIdentity();
	glTranslatef(2.0f, 0.0f, -10.0f);
	glScalef(scale, scale, scale); //ũ�⺯ȯ
	glRotatef(rot, 0.0f, 1.0f, 0.0f); //Y���� �߽����� ȸ��
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f); //Z���� �߽����� 45��ȸ��, ������
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.4f, -0.4f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 0.4f, -0.4f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 0.4f,  0.4f, 0.0f);
		glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-0.4f,  0.4f, 0.0f);
	glEnd();
	
	rot += 0.1f; //ȸ������
	scale += factor; //ũ�� ��ȯ ����

	if(scale >= 5.0f)
	{
		factor = -factor;
	}
	else if(scale <= 0.0f)
	{
		factor = -factor;
	}
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE))
		return EXIT_FAILURE;
	return app.Run();
}