#include<iostream>
<<<<<<< HEAD
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
=======
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
>>>>>>> 92b74db7bfe9b9e8c616f02c4a698cd36e3413ea
