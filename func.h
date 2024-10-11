#pragma once

#include <map>
#include <iostream>

using namespace std;


extern map<char, unsigned short> dictionary;

bool add_a(unsigned short & a, const unsigned short value);
bool add_b(unsigned short & b, const unsigned short value);
void mov_a(unsigned short & a, const unsigned short value);
void mov_b(unsigned short & b, const unsigned short value);
void mov_a_b(unsigned short & a, const unsigned short & b);
void mov_b_a(const unsigned short & a, unsigned short & b);
void jmp(unsigned short& index, const unsigned short value);
void jnc(const unsigned short c, unsigned short& index, const unsigned short value);
void in_a(unsigned short & a);
void in_b(unsigned short & b);
void out_b(const unsigned short b, unsigned short& out);
void out_im(const unsigned short value, unsigned short& out);
