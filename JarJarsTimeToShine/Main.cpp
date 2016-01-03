
#include <Windows.h>
#include <Platforms.h>
#include <sstream>

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPWSTR lpCmdLine, INT nCmdShow) {
	Platforms::matrix m = Platforms::matrix::Identity(3);
	m = Platforms::matrix::Identity(4);
	m = Platforms::mpow(m, 2);
	std::wostringstream k;
	k << m << std::endl;
	OutputDebugString(L"\n\nJar Jar says hello!\n\n");
	OutputDebugString(k.str().c_str());
	OutputDebugString(L"\n\nJar Jar says good bye!\n\n");
	return 0;
}