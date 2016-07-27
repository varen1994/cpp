#include<iostream>
using namespace std;

class Virus {
  public:
  int initial_Cell;
  int a,b;

  Virus()  {
    initial_Cell = 1;
    cin>>a>>b;
  }

  long int refactorVirus(long int initialValue,int steps)  {
    while(steps--)  {
      initialValue = (initialValue*a*0.5)+(initialValue*b*0.5);   
      initialValue %= 1000000007;  
    }
      return initialValue;
  }
};


int main()  {
  Virus V;
  int steps;   
  cin>>steps;
  cout<<V.refactorVirus(1,steps);
  return 0;
}

