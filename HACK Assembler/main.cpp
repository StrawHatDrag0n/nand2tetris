#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include"parser.h"
#include"coder.h"

using namespace std;
int counter = 0;

int main(int argc,char *argv[])
{
  string file_name = argv[1];
  string instruction;
  initialise_table();
  parser P;
  coder C;
  ifstream file(file_name.c_str());
  int pos = file_name.find(".");
  string str = file_name.substr(0,pos);
  str = str + ".hack";
  ofstream file_out(str);
  if(file == NULL)
  {
    cout<<"File Not Found"<<endl;
    return 1;
  }
  else
  {
    while(getline(getline(file,instruction),instruction,'\r'))
    {

      P.parse(instruction);
      //C.code(P,file_out);
    }
    counter++;
    //Display();
    P.reset();
    P.reset_ram();
    file.clear();
    file.seekg(0,ios::beg);
    while(getline(getline(file,instruction),instruction,'\r'))
    {
        P.parse(instruction);
        C.code(P,file_out);
        P.reset();
        C.reset();
    }
    //Display();
  }
  return 0;
}
