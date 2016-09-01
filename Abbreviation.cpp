#include<iostream>
#include<string>
using namespace std;

int occurence(string a,char b,int index)  {
  for(int i=index;i<a.length();i++)  {
      if(a[i]==b)  {
          return i+1; 
       }
   }
return a.length();
}


bool findAbbreviation(string a,string b)  {
  int index = 0;
  for(int i=0;i<b.length();i++)  {
         index = occurence(a,b[i],index);
          if(index==a.length() && i<b.length()-1)  {
            return false;
           }
       }
 return true;      
}


int main()  {
  string a,b;
  int q;
  cin>>q;

for(int j=0;j<q;j++)  {
  cin>>a;
  cin>>b;
      for(int i=0;i<a.length();i++)  {
        if(a[i]>95)  {
           a[i]-=32; 
        }
      }
      
    if(a!=b)  { 
      if(findAbbreviation(a,b)==true)  {
        cout<<"YES";
      }
      else {
        cout<<"NO";
      }
    }
    else {
       cout<<"YES";
    }
     cout<<"\n";
  }
return 0;
}
