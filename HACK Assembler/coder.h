#ifndef CODER_H
#define CODER_H

#include<string>
#include<iostream>
#include"table.h"
#include"parser.h"

using namespace std;

class coder{
  string bi_cp, bi_jp, bi_dt, bi_addre,bi_inst;
public:
  void bi_jump(string);
  void code(parser&,ofstream&);
  void codeaddre(string);
  void bi_comp(string);
  void bi_dest(string);
  void reset();
  void bi_instruction();
  void write_instruction(ofstream&);
};

#endif
