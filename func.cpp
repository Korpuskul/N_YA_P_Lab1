#include "func.h"
#include "conio.h"

map<char, unsigned short int> dictionary = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15}
};


bool add_a(unsigned short int & a, const unsigned short int value) {
    a += value;
    if (a >= 16) {
        a = a % 16;
        return true;
    }
    return false;
}

bool add_b(unsigned short int & b, const unsigned short int value) {
    b += value;
    if (b >= 16) {
        b = b % 16;
        return true;
    }
    return false;
}

void mov_a(unsigned short int & a, const unsigned short int value) { a = value; }

void mov_b(unsigned short int & b, const unsigned short int value) { b = value; }

void mov_a_b(unsigned short int & a, const unsigned short int & b) { a = b; }

void mov_b_a(const unsigned short int & a, unsigned short int & b) { b = a; }

void jmp(unsigned short int& index, const unsigned short int value) { index = value * 2; }

void jnc(const unsigned short int c, unsigned short int& index, const unsigned short int value) {
    if (c == true) { index = value * 2; }
}

void in_a(unsigned short int & a) {
    unsigned short int value = 0;
    value = getch();
    a = value;
    }

void in_b(unsigned short int & b) {
    unsigned short int value = 0;
    value = getch();
    b = value;
}

void out_b(const unsigned short int b, unsigned short int& out) { out = b; }

void out_im(const unsigned short int value, unsigned short int& out) { out = value; }