#include<iostream>
#include<string>
#include<list>
#include"parser.h"
#include"table.h"
#include<cctype>

class parser;

extern int counter;

using namespace std;

void parser::address(string instruction)
{
  int pos = instruction.find("@");
  string symbol = instruction.substr(pos+1,instruction.length());
  if(isNumber(symbol))
  {
    //cout<<symbol<<"symbol"<<endl;
    addre = symbol;
  }
  else if(!isThere(symbol))
  {
    AddEntry(symbol,RAM++);
    addre = getAddress(symbol);
  }
  else
  {
      addre = getAddress(symbol);
  }
  //cout<<"Address :"<<addre<<endl;
}
void parser::jump(string instruction)
{
  int pos = instruction.find(";");
  if(pos != -1)
    jp = instruction.substr(pos+1,instruction.length());
    string::iterator i = jp.begin();
    while(i != jp.end())
    {
        if(*i == ' ')
          i =jp.erase(i);
        else
         i++;
    }
  //cout<<jp<<")"<<endl;
}
void parser::comp(string instruction)
{
  int pos = instruction.find("=");
  int pos_2 =  instruction.find(";");
  int p1 = instruction.find_last_of(" ");
  //cout<<instruction<<endl;
  if(pos != -1)
    cp = instruction.substr(pos+1,pos_2-1);
  else
      cp = instruction.substr(0,pos_2);

  int size = cp.length();
  string::iterator i = cp.begin();
  while(i != cp.end())
  {
      if(*i == ' ')
        i =cp.erase(i);
      else
       i++;
  }
  //cout<<"("<<cp<<")"<<endl;
}
void parser::dest(string instruction)
{
  int pos = instruction.find("=");
  //int pos_2 = instruction.find(";");
  if(pos != -1)
    dt = instruction.substr(0,pos);
  else
      dt.clear();
  /*if(pos != -1)
  {
    dt = instruction.substr(0,pos);
    int pos = dt.find_last_of(" ");
    dt = dt.substr(pos+1,dt.length());
    cout<<dt<<")"<<endl;
    return;
  }
  if(pos_2 != -1)
  {
    dt = instruction.substr(0, pos_2);
    int pos = dt.find_last_of(" ");
    dt = dt.substr(pos+1,dt.length());
    cout<<dt<<")"<<endl;
    return;
  }*/
  //cout<<"("<<dt<<")"<<endl;
  string::iterator i = dt.begin();
  while(i != dt.end())
  {
      if(*i == ' ')
        i = dt.erase(i);
      else
       i++;
  }
}
void parser::parse(string instruction)
{
  if (instruction.find("//") != string::npos)
  {
    int pos = instruction.find("//");
    instruction =  instruction.substr(0,instruction.find("//"));
  }
  //cout<<"("<<instruction<<")"<<endl;
  if(space(instruction))
  {
    return;
  }
  else if (instruction.find("//") != string::npos)
  {
    return;
  }
  else if(instruction.find("(") != string::npos)
  {
    int first = instruction.find("(");
    int last  = instruction.find(")");
    string str = instruction.substr(first+1,last-1);
    //cout<<instruction<<endl;
    //cout<<ROM<<endl;
    if(!isThere(str))
    {
      //cout<<ROM<<"Symbol not present"<<endl;
      int rom = ROM;
      AddEntry(str,rom);
    }
    else
    {
      //cout<<"symbol present" <<ROM<<endl;
      int rom = ROM;
      replace(str,rom);
    }
  }
  else if(instruction.find("@") != string::npos)
  {
    ++ROM;
    if(counter == 1)
      address(instruction);
    //cout<<"Address"<<ROM<<endl;
  }
  else
  {
    ++ROM;
    //cout<<"C instruction"<<ROM<<endl;
    comp(instruction);
    dest(instruction);
    jump(instruction);
    //cout<<dt+cp+jp;
  }
}
bool parser::isNumber(string str)
{
  for(int i = 0, n = str.length(); i < n; i++)
  {
    if(!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}
bool parser::space(string str)
{
  int flag = 0;
  for(int i = 0, n = str.length(); i < n; i++)
  {
    if(str[i] == ' ')
    {
      flag = 0;
    }
    else
    {
      flag = 1;
      break;
    }
  }
  if(flag)
  {
    return false;
  }
  else
  {
      return true;
  }
}
void parser::reset_ram()
{
  RAM = 16;
  ROM = 0;
}
void parser::reset()
{
  jp.clear();
  dt.clear();
  cp.clear();
  addre.clear();
}
