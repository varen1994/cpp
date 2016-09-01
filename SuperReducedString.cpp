#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct node {
  int count;
   char c;
};

vector<struct node>v;

void check_In_Vector(char c)  {
  bool flag = false;    
  for(int i=0;i<v.size();i++)  {
    struct node temp = v[i];
    if(temp.c==c)  {
        temp.count+=1;
        v[i] = temp;
        return ;
    } 
  }   
   struct node temp;
   temp.count = 1;
   temp.c = c;
   v.push_back(temp);
   return ;
}

void show()  {
    for(int i=0;i<v.size();i++)  {
        struct node temp = v[i];
         if(temp.count%2==1)  {
           cout<<temp.c;
         } 
     }  
return ;
}

int main() {
    char c;
    cin>>c;
    struct node temp;
    temp.count = 1;
    temp.c = c;
    v.push_back(temp);
     while(c!='\n')  {
       check_In_Vector(c);
       cin>>c;   
     }
    show();
    return 0;
}

