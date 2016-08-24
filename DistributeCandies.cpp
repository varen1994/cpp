#include<iostream>
#include<vector>

using namespace std;
vector<int>v;
int arr[100000];
int noe;

void go_backward(int pos)  {
    while(pos>0)  {
        if(arr[pos-1]>arr[pos])  {
            v[pos]+=1;
            v[pos-1]+=1;
        }
        else {
            return ;
        }
        pos-=1;
    }
    return ;
}

int main()  {
     cin>>noe;
     for(int i=0;i<noe;i++)  {
        cin>>arr[i];
     }
    v.push_back(1);
    for(int i=1;i<noe;i++)  {
        for(int j=0;j<v.size();j++)  {
            cout<<v[j]<<"  ";
        }
        cout<<"\n";
        
        if(arr[i-1]>arr[i])  {
      
            go_backward(i-1);
        }
        else if(arr[i-1]==arr[i])  {
            v.push_back(1);
        }
        else {
            v.push_back(v[v.size()-1]+1); 
        } 
    }

       int candies=0;
        for(int j=0;j<v.size();j++)  {
            candies +=v[j];
        }

      cout<<"candies = "<<candies<<"\n";  
    return 0;
}
