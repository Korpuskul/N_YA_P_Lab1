#include <fstream>
#include <unistd.h>
#include <bitset>
#include <cstdint>
#include "func.h"
#include "conio.h"

#define MEMORY_SIZE 16
#define MAX_REG_VALUE 15

struct Data {
    uint8_t A = 0;
    uint8_t B = 0;
    uint8_t PC = 0;
    bool FLAG = false;
};

reinterpret_cast<char*> read_buffer();
void handler(uint8_t memory[], unsigned short& index, Data& data);
void clear();


string to_binary(uint8_t value, int bits = 4) {
    return bitset<4>(value).to_string();
}


reinterpret_cast<char*> read_buffer() {
    ifstream file ("file.bin", ios::binary);

    if (file.is_open()) {
        cout << "File is open" << endl;

        uint8_t memory[MEMORY_SIZE] = {};

        // Считываем данные из файла в буфера
        file.read(reinterpret_cast<char*>(memory), MEMORY_SIZE);
        
        // Выводим буфер в терминал
        for (size_t i = 0; i < buffer.size(); i++) {
            cout << buffer[i];
        }
        cout << endl;

        file.close();

        return memory;
    } else {
        cout << "File is not open" << endl;
    }
}

void handler(uint8_t memory[], unsigned short& index, Data& data) {
    uint8_t instruction = memory[data.PC];
    uint8_t opcode = (instruction >> 4) & 0xF;
    uint8_t operand = instruction & 0xF;

    cout << "PC: " << to_binary(data.PC) << " | ";

    data.PC = (data.PC + 1) % MEMORY_SIZE;

    switch (opcode) {
    /* case '0':
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
    } */
    case 0x0:  // ADD A, Im
        cout << "Operation: ADD A, " << to_binary(operand) << " | ";
        setFlag((data.A + operand) > MAX_REG_VALUE); // Устанавливаем флаг перед сложением
        data.A = (data.A + operand) % MAX_REG_VALUE;
        cout << "FLG: " << data.FLAG << endl; // Вывод флага 
        break;

    case 0x5:  // ADD B, Im
        cout << "Operation: ADD B, " << to_binary(operand) << " | ";
        setFlag((data.B + operand) > MAX_REG_VALUE);
        data.B = (data.B + operand) % MAX_REG_VALUE;
        cout << "FLG: " << data.FLAG << endl; 
        break;

    case 0x3:  // MOV A, Im
        cout << "Operation: MOV A, " << to_binary(operand) << " | ";
        data.A = operand;
        break;

    case 0x7:  // MOV B, Im
        cout << "Operation: MOV B, " << to_binary(operand) << " | ";
        data.B = operand;
        break;

    case 0x1:  // MOV A, B
        cout << "Operation: MOV A, B | ";
        data.A = data.B;
        break;

    case 0x4:  // MOV B, A
        cout << "Operation: MOV B, A | ";
        data.B = data.A;
        break;

    case 0xF:  // JMP Im
        cout << "Operation: JMP " << to_binary(operand) << " | ";
        data.PC = operand;
        break;

    case 0xE:  // JNC Im
        cout << "Operation: JNC " << to_binary(operand) << " | ";
        if (data.FLAG == 0) {
            data.PC = operand;
        }
        data.FLAG = false; // Сбрасываем флаг *после* каждого JNC
        break;

    case 0x2:  // IN A
        cout << "Operation: IN A | ";
        cout << "Input value for A (0-15): ";
        cin >> data.A;
        data.A &= MAX_REG_VALUE;
        break;

    case 0x6:  // IN B
        cout << "Operation: IN B | ";
        cout << "Input value for B (0-15): ";
        cin >> data.B;
        data.B &= MAX_REG_VALUE;
        break;

    case 0x9:  // OUT B
        cout << "Operation: OUT B | Output B: " << to_binary(data.B) << endl;
        break;

    case 0xB:  // OUT Im
        cout << "Operation: OUT Im | Output Immediate: " << to_binary(operand) << endl;
        break;

    }

    cout << "To finish, press \"ctrl + C\"" << endl;
    cout << "A=" << data.A << ", B=" << data.B << ", C=" << data.C << ", INPUT=" << data.input << endl;
    data.C = false;
}


void clear() {
    cout << "\033[2J\033[1;1H";
}

int main(void) {
    Data data;

    read_buffer();   

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
                i += 2;
            }
        }
        break;
    case 49: // работает по таймеру
        for (; true; i += 2) {
            clear();
            handler(buffer, i, data);
            sleep(1);
        }
        break;
    default:
        clear();
        break;
    }

    return 0;
}
