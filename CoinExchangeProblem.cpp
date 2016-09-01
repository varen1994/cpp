#include<iostream>
#include<vector>
#import<algorithm>
#define AMOUNT 166	
using namespace std;

int coinsArr[23] = {5,37,8,39,33,17,22,32,13,7,10,35,40,2,43,49,46,19,41,1,12,11,28};
int positionOfLastAdded(int a);
int noe=23;
int pairs = 0;

int noOfPairs(vector<int>V,int amount)  {

   int pos;
   if(amount>0)  {
      pos = positionOfLastAdded(V[V.size()-1]);
   }
   else {
    pos = 0;
   }
 
    for(int i=pos;i<noe;i++)  {  
      if(amount+coinsArr[i]<AMOUNT)  {
         V.push_back(coinsArr[i]);
         noOfPairs(V,amount+coinsArr[i]);
         V.pop_back();
       }
      else if(amount+coinsArr[i]==AMOUNT)  {
       /*  for(int j=0;j<V.size();j++)  {        
            cout<<V[j]<<"  ";
          }
         cout<<coinsArr[i]<<"\n";
        */
        pairs+=1;
      }
      else {
        return 0;
      }
   }
return 0;
}


int positionOfLastAdded(int value) {
  for(int i=0;i<noe;i++)  {
     if(coinsArr[i]==value)  {
       return i;
     }
  }
return 0;
}


int main()  {
  sort(coinsArr,coinsArr+noe);
  vector<int>V;
   noOfPairs(V,0);
   cout<<pairs; 
  return 0;
}
