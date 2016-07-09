#include<iostream>
#include<map> 
#include<string>
#include<cstdlib>
using namespace std;

class Dictionary  {
  public:
  map<string,long int>List;

  void addValueToMap()  {
    int numberOfValues;
    cin>>numberOfValues;
    while(numberOfValues--)  {
     string name;
     long int phoneNo;
     cin>>name;
     cin>>phoneNo; 
     List.insert(pair<string,long int>(name,phoneNo));
    } 
     return ; 
   } 

  bool traverseMap(string name)  {
     map<string,long int>::iterator i; 
     for(i=List.begin();i!=List.end();i++)  {
         if((*i).first==name)  { 
           return true; 
          }
      }
      return false;
   }
   
   void printValuesCorrToKey()  {
      string name;
      while(1)  
       {
          cin>>name;
          if(name.length())  { 
              if(traverseMap(name)) {
                cout<<List[name]; 
               }
               else  {
                cout<<"Not Found";
               }  
           }
           else  {
              break; 
            }  
          cout<<"\n"; 
        } 
     }
};

int main()  {
  Dictionary dict;
  dict.addValueToMap();
  dict.printValuesCorrToKey();
  return 0;
}
