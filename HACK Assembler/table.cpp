#include<iostream>
#include<list>
#include<string>
#include"table.h"

extern int counter;
using namespace std;

string Symbols[] = {
  "SP", "LCL", "ARG" , "THIS", "THAT",
  "R0", "R1", "R2", "R3", "R4", "R5", "R6",
  "R7", "R8", "R9", "R10", "R11", "R12", "R13",
  "R14", "R15", "SCREEN", "KBD"
};
string Addresses[] = {
  "0", "1", "2", "3", "4", "0", "1", "2", "3",
  "4", "5", "6", "7", "8", "9", "10", "11", "12",
  "13", "14", "15", "16384", "24576"
};
string dt_table[] ={
  "M", "D", "MD", "A", "AM", "AD", "AMD"
};
string bi_dt_table[] = {
  "001", "010", "011", "100", "101", "110",
  "111"
};
string cp_table_D[] = {
  "0", "1", "-1", "D", "A", "!D", "!A", "-D", "-A",
  "D+1", "A+1", "D-1", "A-1", "D+A", "D-A", "A-D",
  "D&A", "D|A"
};
string cp_table_M[] = {
  "0", "1", "-1", "D", "M", "!D", "!M", "-D", "-M",
  "D+1", "M+1", "D-1", "M-1", "D+M", "D-M", "M-D",
  "D&M", "D|M"
};
string bi_cp_table[] = {
  "101010", "111111", "111010", "001100", "110000",
  "001101", "110001", "001111", "110011", "011111",
  "110111", "001110", "110010", "000010", "010011",
  "000111","000000", "010101"
};
string jp_table[] = {
  "JGT", "JEQ", "JGE", "JLT", "JNE", "JLE",
  "JMP"
};
string bi_jp_table[] = {
  "001", "010", "011", "100", "101", "110",
  "111"
};

list<data> li;
list<data>::iterator i;

void AddEntry(string str, string num)
{
  if(!isThere(str))
  {
    data d;
    d.str = str;
    d.address = num;
    li.push_back(d);
  }
}
void AddEntry(string str, int number)
{
    if(!isThere(str))
    {
      data d;
      string num(to_string(number));
      d.str = str;
      d.address = num;
      li.push_back(d);
    }
}
bool isThere(string str)
{
  for(i = li.begin(); i != li.end(); i++)
  {
      if(i-> str == str)
      {
          return true;
      }
  }
  return false;
}
string getAddress(string str)
{
  for(i = li.begin(); i != li.end(); i++)
  {
      if(i-> str == str)
      {
          return i->address;
      }
  }
}
void Display()
{
  for(i = li.begin(); i != li.end(); i++)
  {
      cout<<i->str<<endl;
      cout<<i->address<<endl;
  }
}
void replace(string str, int number)
{
  for(i = li.begin(); i != li.end(); i++)
  {
      if(i->str == str)
      {
        string num(to_string(number));
        i->address = num;
      }
  }
}
void initialise_table()
{
  for(int i = 0; i < 23; i++)
  {
    AddEntry(Symbols[i],Addresses[i]);
  }
}
