#include "func.h"
#include "conio.h"

map<char, unsigned short> dictionary = {
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


bool add_a(unsigned short & a, const unsigned short value) {
    a += value;
    if (a >= 16) {
        a = a % 16;
        return true;
    }
    return false;
}

bool add_b(unsigned short & b, const unsigned short value) {
    b += value;
    if (b >= 16) {
        b = b % 16;
        return true;
    }
    return false;
}

void mov_a(unsigned short & a, const unsigned short value) { a = value; }

void mov_b(unsigned short & b, const unsigned short value) { b = value; }

void mov_a_b(unsigned short & a, const unsigned short & b) { a = b; }

void mov_b_a(const unsigned short & a, unsigned short & b) { b = a; }

void jmp(unsigned short& index, const unsigned short value) { index = value * 2; }

void jnc(const unsigned short c, unsigned short& index, const unsigned short value) {
    if (c == true) { index = value * 2; }
}

void in_a(unsigned short & a) {
    unsigned short value = 0;
    value = getch();
    a = value;
    }

void in_b(unsigned short & b) {
    unsigned short value = 0;
    value = getch();
    b = value;
}

void out_b(const unsigned short b, unsigned short& out) { out = b; }

void out_im(const unsigned short value, unsigned short& out) { out = value; }