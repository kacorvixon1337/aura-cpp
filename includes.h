#pragma once

#include <Windows.h>
#include <winsock2.h>

#define GLEW_STATIC
#include "includes/glew.h"
#include <gl/gl.h> 
#include <d3d9.h>

#include "Loader.h"
#include "LoaderUtils.h"
#include "Resources.h"
#include "includes/MinHook.h"
#include "Utils.h"
#include "minecraftFont.h"
#include "cheats/gui/imgui.h"
#include "cheats/gui/imgui_impl_win32.h"
#include "cheats/gui/imgui_impl_opengl2.h"
#include "nigger.h"
#include "BpPlayer.h"
#include "cheats/icons/icons.h"
#include "cheats/icons/iconcpp.h"
#include "cheats/icons/font.h"
#include "Radius.h"
#include "Position.h"
//#include "includes.h"
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib,"WS2_32.Lib")


typedef BOOL(__stdcall* twglSwapBuffers) (_In_ HDC hDc);
typedef BOOL(__stdcall* tglCallList) (GLuint list);
typedef void(__stdcall* tGlScalef)(float, float, float);
typedef void(__stdcall* tglTranslatef)(float, float, float);
typedef void(__stdcall* tglOrtho)(double left, double right, double bottom, double top, double zNear, double zFar);
typedef LRESULT(CALLBACK* WndProc_t) (HWND, UINT, WPARAM, LPARAM);
typedef INT(WSAAPI* tWSASend) (SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);

twglSwapBuffers oSwapBuffers = NULL;
tglCallList oglCallList;
tGlScalef pniggerv2 = nullptr;
tglTranslatef ogltranslatef = nullptr;
tglOrtho oglOrtho = nullptr;
WndProc_t o_wndproc;
tWSASend oWSASend;

HWND window;
bool done = false;

JavaVM* jvm_;
JNIEnv* env_;

Position chest;
Position entity;
Position largeChest;

LPCSTR TargetProcess = "javaw.exe";


static bool ContextCreated = false;
static HGLRC g_Context = (HGLRC)NULL;

jmethodID userNameGet;
jint playersSize;
jstring userNamegraczza;
bool niemawtabie = false;
static ImVec4 active = ImColor(35, 120, 247);
static ImVec4 inactive = ImColor(65, 71, 67);

vector<BpPlayer> items;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (cheats::showmenu)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}

	return CallWindowProcA(o_wndproc, hWnd, uMsg, wParam, lParam);
}

void draw(Position& position, Radius radius)
{
	for (int i = 0; i < position.modelview.size(); i += 16)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(position.projection.data() + i);

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(position.modelview.data() + i);

		glLineWidth(2.0F);
		glColor4f(color10tak, color20tak, color30tak, 1.0F);

		glBegin(GL_LINES);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glEnd();

		glColor4f(color10tak, color20tak, color30tak, 0.2F);

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glEnd();


		glLoadIdentity();

		glColor4f(1.0F, 1.0F, 1.0F, 0.3F);

		glBegin(GL_LINES);
		glVertex3f(0, 0, -0.1F);
		glVertex3f((position.modelview.data() + i)[12], (position.modelview.data() + i)[13], (position.modelview.data() + i)[14]);
		glEnd();
	}

	position.projection.clear();
	position.modelview.clear();
}

void draw_lines(Position& position, Radius radius) {
	for (int i = 0; i < position.modelview.size(); i += 16)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(position.projection.data() + i);

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(position.modelview.data() + i);

		glLoadIdentity();

		glColor4f(1.0F, 1.0F, 1.0F, 0.3F);

		glBegin(GL_LINES);
		glVertex3f(0, 0, -0.1F);
		glVertex3f((position.modelview.data() + i)[12], (position.modelview.data() + i)[13], (position.modelview.data() + i)[14]);
		glEnd();
	}

	position.projection.clear();
	position.modelview.clear();
}

void savePosition(Position& position, float offsetX, float offsetY, float offsetZ)
{
	float projection[16]{};
	glGetFloatv(GL_PROJECTION_MATRIX, projection);

	float modelview[16]{};
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

	// Position adjustment (Taken from the source code of the GLM library)
	float m3[4]{};

	for (int i = 0; i < 4; ++i)
	{
		m3[i] = modelview[i] * offsetX
			+ modelview[i + 4] * offsetY
			+ modelview[i + 8] * offsetZ
			+ modelview[i + 12];
	}

	memcpy(modelview + 12, m3, sizeof(m3));

	position.projection.insert(position.projection.end(), begin(projection), end(projection));
	position.modelview.insert(position.modelview.end(), begin(modelview), end(modelview));
}