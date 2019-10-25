#ifndef TABLE_H
#define TABLE_H

#include<iostream>
#include<string>
#include<list>
#include"parser.h"

using namespace std;

extern string Symbols[];
extern string Addresses[];
extern string bi_jp_table[];
extern string jp_table[];
extern string bi_cp_table[];
extern string cp_table_M[];
extern string cp_table_D[];
extern string bi_dt_table[];
extern string dt_table[];

class data{
public:
  string str;
  string address;
};
void replace(string str, int number);
void Display();
void initialise_table();
void AddEntry(string str, int number);
bool isThere(string str);
string getAddress(string str);
#endif
