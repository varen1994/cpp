#include<iostream>
using namespace std;

int callA = 0;
int callB = 0;
int callC = 0;


class A
{
  protected:
  void func(int &a)
  {
    a = a*2;
    callA++;
  }
};


class B
{
  protected:
  void func(int &a)
  {
    a=a*3;
    callB++;
  } 
};


class C
{
  protected:
  void func(int &a)
  {
    a=a*5;
    callC++;
  }
};


class D:protected A,protected B,protected C
{
  int val;
  protected:
  A a;
  B b;
  C c;
  public:
  D()
  {
    val = 1;
  }
  void update_val(int new_val)
  {
    a.func(val);
    b.func(val);
    c.func(val);  
  }
  void check(int);
};

void D::check(int new_val)
{
  update_val(new_val);
  cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<"times";
  cout<<"B's func called"<<callB<<callB<<" times";
  cout<<"C's func called "<<callC<<" times "<<endl;
}


int main()
{ 
 D d;
 int new_val;
 cin>>new_val;
 d.check(new_val);
 return 0;
}

