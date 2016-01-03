
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <Platforms/Matrix.h>


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, INT nCmdShow) {
	using namespace std;
	Platforms::Game* game = new Platforms::Game();
	Platforms::Engine::CreateEngine(game);
	wostringstream st;
	float f [] = { 1, 2, 7, 1, 0, 8 };
	Platforms::matrix A (2, 3, f);
	Platforms::matrix B = 3 * A.T();
	Platforms::matrix C = A * B;
	st << "\n" << "A:" << A << " B:" << B << " AB:" << C << "\n" << endl;
	OutputDebugString(st.str().c_str());
	Platforms::Engine::DestroyEngine();
	delete game;
	return 0;
}