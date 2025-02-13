#include <windows.h>

extern "C" void _start() {
    HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
    if (hConsoleOut == INVALID_HANDLE_VALUE || hConsoleIn == INVALID_HANDLE_VALUE) {
        return;
    }

    const char* prompt = "Enter something: ";
    DWORD written;
    WriteConsoleA(hConsoleOut, prompt, 15, &written, NULL);

    char input[100];
    DWORD read;
    if (ReadConsoleA(hConsoleIn, input, sizeof(input) - 1, &read, NULL)) {
        input[read] = '\0';
    }

    const char* message = "You entered: ";
    WriteConsoleA(hConsoleOut, message, 14, &written, NULL);

    WriteConsoleA(hConsoleOut, input, read, &written, NULL);

    // Exit the program
    ExitProcess(0);
}

