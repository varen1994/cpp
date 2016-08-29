#include<iostream>
#include<cstdio>
#include<string>
using namespace std;


int main()  {
   int N,count;
   cin>>N;
   string a = "#";
    std::string s = std::to_string(N);
    std::string reqFormat = "%"+s+"s";
    for(int i=0;i<N;i++)  {
        printf(reqFormat, a.c_str());
        a+="#";
    }
   return 0;
}
