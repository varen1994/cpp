#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Dictionary  {
  int phoneNumber;
  string name;
};

int main() {
    int i,n;
    int phoneNumber;
    string name;
        
    cin>>n;
    struct Dictionary *dict = (struct Dictionary *)malloc(sizeof(struct Dictionary)*n);
    
    for(i=0;i<n;i++)  {
       struct Dictionary *temp = (dict+i);
       cin>>name;
       cin>>phoneNumber;
       temp->name = name;
       temp->phoneNumber = phoneNumber;
    }
    cin>>name;
    while(name.length())  {
       
           bool flag = false;
           for(i=0;i<n;i++)  {
              struct Dictionary *temp = (dict+i);
              if(temp->name==name)  {
                  cout<<temp->name<<"="<<temp->phoneNumber<<"\n";
                  flag = true;
              }
           }
           if(!flag)  {
               cout<<"Not found\n";
           } 
        cin>>name;
    }
   return 0;
}


