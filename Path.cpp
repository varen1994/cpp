// Find path form A to B point
#include<iostream>
using namespace std;

class PathFromAtoB  {
  public:
  int Xmin,Ymin;
  int Xmax,Ymax;
  int noOfPaths;
 int noOfNodes;  
 int initialPathLine;  
   PathFromAtoB() {
    noOfPaths = 0;
    cout<<"Xmin  = ";
    cin>>Xmin;
    cout<<"Ymin  = ";
    cin>>Ymin;
    cout<<"Xmax  = ";
    cin>>Xmax;
    cout<<"Ymax =  ";
    cin>>Ymax;
   cout<<"No of Nodes = "; 
     cin>>noOfNodes; 
    initialPathLine = 0; 
    this->allPaths(Xmin,Ymin,initialPathLine);
  }

  void allPaths(int x,int y,int initialPathLine);
};

void PathFromAtoB::allPaths(int x,int y,int initialPathLine)  {
  cout<<"x = "<<x<<" Y = "<<y<<"\n";
  if((x>=Xmin && y>=Ymin ) && (x<=Xmax && y<=Ymax) && initialPathLine<=noOfNodes)  {
     if(x==Xmax && y==Ymax)  {
        cout<<"incremented "; 
        noOfPaths += 1;
      }
      else {
          allPaths(x,y-1,initialPathLine+1); 
          allPaths(x-1,y,initialPathLine+1); 
          allPaths(x+1,y,initialPathLine+1);
          allPaths(x,y+1,initialPathLine+1);
       }
  }
  else {
     return ;
   }
 return ;
}



int main()  {
   PathFromAtoB P;
   cout<<P.noOfPaths;
   return 0;
}
