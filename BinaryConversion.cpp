#include<iostream>

using namespace std;

/* 63636363 = 6 */
/* for 1000 = 3    remove flag */
int convertBinary(int n)  {
  int max = 0;
  int to = 0;
  bool flag = false;
  while(n) {
    if(n&1==1)  {
      cout<<"1";
      if(max<to && flag==true)  {
         max=to;
       }
       to=0;
       flag = true;
    }
    else {
      cout<<"0";
      to+=1;
    }
    n = n>>1;
  }
return max;
}

int main()  {
  int number;
  cout<<"Enter Number = ";
  cin>>number;
  int zeroes = convertBinary(number);  
  cout<<"zeroes max = "<<zeroes;
  return 0;
}
