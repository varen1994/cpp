#include<iostream>
#include<vector>

using namespace std;
vector <int> v;
int ratingArr[100000],noe;
int totalCandies;

void incrementPrevious(int pos)  {
   while(pos-1>=-1) {
      if(ratingArr[pos-1]>ratingArr[pos] && v[pos-1]<=v[pos]) {
        v[pos-1]+=1;
      }  
      else {
        return ;
      }
      pos-=1;
    }
    return ;
}

void findMinCandies()  {
  v.push_back(1);
  for(int i=1;i<noe;i++)  {
    if(ratingArr[i-1]>ratingArr[i])  {
      v.push_back(1);
      incrementPrevious(i);
    }
    else if(ratingArr[i-1]==ratingArr[i]){
        v.push_back(i-1);
    }
    else {
        v.push_back(v[v.size()-1]+1);
    }
  }
   
   int totalCandies = 0;
   for(int i=0;i<v.size();i++)  {
      totalCandies+=v[i];
    }
 
  return ;
}


int main()  {
     cin>>noe;
     for(int i=0;i<noe;i++)  {
        cin>>ratingArr[i];
     }
    findMinCandies();
    cout<<totalCandies;
    return 0;
}
