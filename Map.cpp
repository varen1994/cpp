#include<iostream>
#include<map> 
#include<string.h>
using namespace std;

class Dictionary  {
  public:
  map<string,long int>List;
  void addValueToMap()  {
     List.insert(std::make_pair("varender",128093));
     List.insert(std::make_pair("Rohan",128067));
     List.insert(std::make_pair("Sudhanshu",128083));
     List["varender"] = List["varender"]+12; 
     cout<<List["varender"]; 
     return ; 
   } 

   void traverseMap()  {
     cout<<"\n"; 
     map<string,long int>::iterator i;
     for(i=List.begin();i!=List.end();++i)  {
         cout<<"{"<<(*i).first<<":";
         cout<<(*i).second<<"}";
         cout<<"\n"; 
      }
     
       return ;
   }
};

int main()  {
  Dictionary dict;
  dict.addValueToMap();
  dict.traverseMap(); 
  return 0;
}
