#include<windows.h>

bool running = true;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (uMsg)
	{	
		case WM_CLOSE:
	
		case WM_DESTROY:
		running = false;
		break;

		default:
		result = DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return result;
	
}

int WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) 
{
	// Create a window class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Windows Class";
	window_class.lpfnWndProc = window_callback;
	
	// Register the window class
	RegisterClass(&window_class);
	
	// Create the window
	HWND window = CreateWindow(window_class.lpszClassName, L"Game Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE,50,50,1920, 1080, NULL, NULL, hInstance, NULL);

	while (running)
	{
		//Input
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		//Simulate

		//Render
	}
}