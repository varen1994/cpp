#include<iostream>
#include<map> 
#include<string.h>
using namespace std;

class Dictionary  {
  public:
  map<string,long int>List;
  void addValueToMap()  {
     List.insert(std::make_pair("varender",128093));
     List["varender"] = List["varender"]+12; 
     cout<<List["varender"]; 
     return ; 
   } 
};

int main()  {
  Dictionary dict;
  dict.addValueToMap();
  return 0;
}
