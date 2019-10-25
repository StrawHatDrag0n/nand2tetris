#ifndef PARSER_H
#define PARSER_H

#include<string>
#include<iostream>
#include"table.h"

using namespace std;

class parser{
  string dt, jp, cp, addre;
  int ROM = 0;
  int RAM = 16;
  friend class coder;
public:
  void parse(string);
  bool space(string);
  void comp(string);
  void dest(string);
  void jump(string);
  void address(string);
  bool isNumber(string);
  void reset();
  void reset_ram();
};

#endif
