#include<iostream>
using namespace std;

void printArr(int *arr,int n)  {
  for(int i=0;i<n;i++)  {
     cout<<*(arr+i)<<"  ";
   }
cout<<"\n";
}

void swapIntegers(int *a,int *b)  {
  *a = *a+*b;
  *b = *a-*b;
  *a = *a-*b;
}


void insertionSort(int *arr,int n)  {
  for(int i=1;i<n;i++)  {
   int j = i;
   while(j>0 && *(arr+j-1)>*(arr+j))  {
      swapIntegers(arr+j-1,arr+j);
      j-=1;
    }
    printArr(arr,n);
  }
  return ;
}


int main()  {
  int arr[5] = {10,9,8,7,6};
  insertionSort(arr,5);
  return 0;
}
