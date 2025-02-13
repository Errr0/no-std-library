#include <windows.h>

int main() {
    // Handle to the console output (stdout)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Writing to console
    const char* message = "Hello, World!\n";
    DWORD written;
    WriteConsole(hConsole, message, 14, &written, NULL);

    // Handle to the console input (stdin)
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    
    // Reading input from the console
    char input[100];
    DWORD read;
    ReadConsole(hInput, input, 100, &read, NULL);
    
    // Writing the input back to console
    WriteConsole(hConsole, "You entered: ", 13, &written, NULL);
    WriteConsole(hConsole, input, read, &written, NULL);
    
    return 0;
}
