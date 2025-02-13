#include <windows.h>

class string {
private:
    char* data;
    size_t length;
    size_t capacity;

public:
    string(const char* str = "") {
        length = 0;
        capacity = 1;
        data = new char[capacity];

        while (str[length] != '\0') {
            if (length + 1 >= capacity) {
                capacity *= 2;  
                char* new_data = new char[capacity];
                for (size_t i = 0; i < length; ++i) {
                    new_data[i] = data[i];
                }
                delete[] data;
                data = new_data;
            }
            data[length++] = str[length];
        }
        data[length] = '\0';
    }

    ~string() {
        delete[] data;
    }

    void append(const char* str) {
        size_t str_len = 0;
        while (str[str_len] != '\0') {
            ++str_len;
        }

        size_t new_length = length + str_len;
        if (new_length + 1 > capacity) {
            while (capacity <= new_length + 1) {
                capacity *= 2;
            }
            char* new_data = new char[capacity];
            for (size_t i = 0; i < length; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }

        for (size_t i = 0; i < str_len; ++i) {
            data[length + i] = str[i];
        }
        length += str_len;
        data[length] = '\0';
    }

    size_t size() const {
        return length;
    }

    char at(size_t index) const {
        if (index < length) {
            return data[index];
        }
        return '\0'; 
    }

    const char* c_str() const {
        return data;
    }

    void print() const {
        HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD written;
        WriteConsoleA(hConsoleOut, data, length, &written, NULL);
    }
};
