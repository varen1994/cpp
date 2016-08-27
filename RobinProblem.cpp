#include<iostream>
#include<string>
using namespace std;

int main()  {
  string hash = "#"; 
  int N;
  cin>>N;
  for(int i=0;i<N;i++)  {
    cout.width(N);
    cout<<hash<<"\n"; 
    hash+="#";
  } 
  return 0;
}   
