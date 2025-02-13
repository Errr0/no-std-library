#include <windows.h>

class io {
    HANDLE hConsoleOut;
    HANDLE hConsoleIn;
public:
    io(){
        hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsoleOut == INVALID_HANDLE_VALUE) {
            return;
        }
        hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
        if (hConsoleIn == INVALID_HANDLE_VALUE) {
            return;
        }
    }
    void print(const char* str) {
        DWORD written;
        WriteConsoleA(hConsoleOut, str, strlen(str), &written, NULL);
    }

    // Method to read input from the console and store it in a string buffer
    void input(char* buffer, size_t bufferSize) {
        DWORD read;
        if (ReadConsoleA(hConsoleIn, buffer, bufferSize - 1, &read, NULL)) {
            buffer[read] = '\0';  // Null-terminate the string
        }
    }
};
