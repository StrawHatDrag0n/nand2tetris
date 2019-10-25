#include<iostream>
#include<fstream>
#include<string>
#include"table.h"
#include"parser.h"
#include"coder.h"

using namespace std;

void coder::bi_jump(string jump)
{
  for(int  i = 0; i < 7; i++)
  {
    if(jump == jp_table[i])
    {
      bi_jp = bi_jp_table[i];
    }
  }
  //cout<<"jump "<<bi_jp<<endl;
}
void coder::bi_dest(string dest)
{
  bi_dt.clear();
  //cout<<"("<<bi_dt<<")"<<endl;
  for(int  i = 0; i < 7; i++)
  {
    if(dest == dt_table[i])
    {
      //cout<<dt_table[i]<<endl;
      //cout<<"("<<dt_table[i]<<"*)"<<endl;
      bi_dt = bi_dt_table[i];
    }
  }
  //cout<<"dest"<<bi_dt<<endl;
}
void coder::bi_comp(string comp)
{
    int pos = comp.find("M");
    if(pos == -1)
    {
      bi_cp ="0";
      for(int i = 0; i < 18; i++)
      {
        if(comp == cp_table_D[i])
        {
          bi_cp = bi_cp + bi_cp_table[i];
        }
      }
    }
    else
    {
      bi_cp = "1";
      for(int i = 0; i < 18; i++)
      {
        if(comp == cp_table_M[i])
        {
          bi_cp = bi_cp + bi_cp_table[i];
        }
      }
    }
    //cout<<"("<<comp<<")"<<endl;
    //cout<<"comp"<<bi_cp<<endl;
}
void coder::code(parser& P, ofstream& out)
{
  if(P.jp == "")
  {
    bi_jp = "000";
  }
  else
  {
    bi_jump(P.jp);
  }
  if(P.cp == "")
  {
    bi_cp = "0000000";
  }
  else
  {
      bi_comp(P.cp);
  }
  if(P.dt == "")
  {
    bi_dt = "000";
  }
  else
  {
    bi_dest(P.dt);
  }
  if(P.addre == "")
  {
    bi_addre = "";
  }
  else
  {
    codeaddre(P.addre);
  }
  bi_instruction();
  write_instruction(out);
  reset();
}
void coder::bi_instruction()
{
  bi_inst = bi_cp+ bi_dt + bi_jp;
  int pos = bi_inst.find("1");
  if(pos == -1)
  {
    bi_inst.clear();
    return;
  }
  else
    bi_inst = "111" + bi_inst;
  if(bi_inst.length() > 16)
  {
    cout<<"Jump : "<<bi_jp<<endl;
    cout<<"Comp : "<<bi_cp<<endl;
    cout<<"Dest : "<<bi_dt<<endl;
    cout<<"Instruction : "<<bi_inst<<endl;
    exit(1);
  }
  //cout<<bi_inst<<endl;
}
void coder::write_instruction(ofstream& out)
{
  if(bi_inst.empty() && !bi_addre.empty())
  {
    out<<bi_addre;
    out<<"\n";
  }
  else if(!bi_inst.empty())
  {
    out<<bi_inst;
    out<<"\n";
  }
}
void coder::codeaddre(string address)
{
  int number = stoi(address,nullptr,10);
  //cout<<"("<<address<<")"<<endl;
  int i;
  while(number)
  {
    i = number % 2;
    number/=2;
    bi_addre.insert(0,to_string(i));
  }
  if(bi_addre.length() <= 15)
  {
    for(int i = bi_addre.length(); i < 16; i++)
    {
      bi_addre.insert(0,"0");
    }
  }
  //cout<<bi_addre<<endl;
}
void coder::reset()
{
  bi_jp.clear();
  bi_cp.clear();
  bi_dt.clear();
  bi_inst.clear();
  bi_addre.clear();
}
