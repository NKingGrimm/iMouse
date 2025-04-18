#include <windows.h>
#include <iostream>

HHOOK mouseHook;

// Mouse hook callback
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_MOUSEMOVE) {
        POINT pt;
        GetCursorPos(&pt);
        HWND hWnd = WindowFromPoint(pt);

        if (hWnd && hWnd != GetForegroundWindow()) {
            if (IsWindowVisible(hWnd) && IsWindowEnabled(hWnd)) {
                SetForegroundWindow(hWnd);
                std::cout << "Activated: " << pt.x << ", " << pt.y << std::endl;
            }
        }
    }

    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

int main() {
    std::cout << "Mouse hook active. Move your cursor to activate windows.\n";

    // Set global low-level mouse hook
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);

    if (!mouseHook) {
        std::cerr << "Failed to install mouse hook.\n";
        return 1;
    }

    // Message loop to keep app alive
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(mouseHook);
    return 0;
}
