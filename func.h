#pragma once

#include <map>
#include <iostream>

using namespace std;


extern map<char, unsigned short int> dictionary;

bool add_a(unsigned short int & a, const unsigned short int value);
bool add_b(unsigned short int & b, const unsigned short int value);
void mov_a(unsigned short int & a, const unsigned short int value);
void mov_b(unsigned short int & b, const unsigned short int value);
void mov_a_b(unsigned short int & a, const unsigned short int & b);
void mov_b_a(const unsigned short int & a, unsigned short int & b);
void jmp(unsigned short int& index, const unsigned short int value);
void jnc(const unsigned short int c, unsigned short int& index, const unsigned short int value);
void in_a(unsigned short int & a);
void in_b(unsigned short int & b);
void out_b(const unsigned short int b, unsigned short int& out);
void out_im(const unsigned short int value, unsigned short int& out);
