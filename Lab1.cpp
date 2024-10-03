#include <fstream>
#include <unistd.h>
#include <vector>
#include "func.h"
#include "conio.h"



struct Data {
    unsigned short int input = 0, A = 0, B = 0, OUT = 0;
    bool C = false;
};

void read_buffer(vector<char>& buffer);
void handler(vector<char>& buffer, unsigned short int& index, Data& data);
void clear();


int main(void) {
    vector<char> buffer(64);
    Data data;

    read_buffer(buffer);   

    cout << "Select the operating mode: by pressing space or by timer (press 1) " << flush;
    char ch;
    unsigned short i = 0;
    ch = getch();
    switch (ch)
    {
    case 32: // работает по нажатию
        clear();
        cout << "To continue, press space, to finish, press \"ctrl + C\"" << endl;
        while (true) {
            if (getch() == 03) { break; }
            else if (getch() == 32) {
                clear();
                handler(buffer, i, data);
                cout << "To finish, press \"ctrl + C\"" << endl;
                cout << "A=" << data.A << ", B=" << data.B << ", C=" << data.C << ", INPUT=" << data.input << ", OUT=" << data.OUT << endl;
                data.C = false;
                i += 2;
            }
        }
        break;
    case 49: // работает по таймеру
        for (; true; i += 2) {
            clear();
            handler(buffer, i, data);
            cout << "To finish, press \"ctrl + C\"" << endl;
            cout << "A=" << data.A << ", B=" << data.B << ", C=" << data.C << ", INPUT=" << data.input << ", OUT=" << data.OUT << endl;
            data.C = false;
            sleep(1);
        }
        break;
    default:
        clear();
        break;
    }

    return 0;
}

void read_buffer(vector<char>& buffer) {
    ifstream file ("test.txt", ios::in | ios::binary);

    if (file.is_open()) {
        cout << "File is open" << endl;

        // Считываем данные из файла в буфера
        file.read(buffer.data(), buffer.size());
        
        // Выводим буфер в терминал
        for (size_t i = 0; i < buffer.size(); i++) {
            cout << buffer[i];
        }
        cout << endl;

        file.close();
    } else {
        cout << "File is not open" << endl;
    }
}

void handler(vector<char>& buffer, unsigned short int& index, Data& data) {
    #define VAL dictionary[buffer[index+1]] // макрос для сокращения
    if (dictionary.find(buffer[index]) == dictionary.end() || dictionary.find(buffer[index+1]) == dictionary.end()) {
        cout << "Unknown command" << endl;
        index = 0;
    } else {
        switch (buffer[index])
        {
        case '0':
            data.C = add_a(data.A, VAL);
            break;
        case '1':
            data.C = add_b(data.B, VAL);
            break;
        case '2':
            mov_a(data.A, VAL);
            break;
        case '3':
            mov_b(data.B, VAL);
            break;
        case '4':
            mov_a_b(data.A, data.B);
            break;
        case '5':
            mov_b_a(data.A, data.B);
            break;
        case '6':
            jmp(index, VAL);
            break;
        case '7':
            jnc(data.C, index, VAL);
            break;
        case '8':
            in_a(data.A);
            break;
        case '9':
            in_b(data.B);
            break;
        case 'A':
            out_b(data.B, data.OUT);
            break;
        case 'B':
            out_im(VAL, data.OUT);
            break;
        case '\0':
            index = 0;
            break;
        default:
            cout << "Unknown command" << endl;
            break;
        }
    }
}

void clear() {
    cout << "\033[2J\033[1;1H";
}
