#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
vector<int>v;


void inputVector(int N)  {
  for(int i=0;i<N;i++)  {
     int temp;
     cin>>temp;
     v.push_back(temp);
  }
  return ;
}

string convertIntToString(int number)  {
  string temp = "";
  while(number)  {
    if(number&1)  {
	  temp+="1"; 
    }
    else {
	  temp+="0";
    }
   number>>=1;
  }
 return temp;
}

string valueToString(int index,int noOfTimes)  {
	string a = "";
	string ip = "";
	if(index%2==0)  {
		ip += "1";
	}
	else {
		ip += "0";
	}
	while(noOfTimes--)  {
		a = a+ip;
	}
return a;	
}

int numberOfOnes(string &bits)  {
	int count = 0;
	for(int i=0;i<bits.length();i++)  {
	    if(bits[i]=='1')  {
		   count+=1;	
		}  
	}
 return count;	
}

int convertStringToInt(string &bits)  {
	int value = 0;
	for(int i=bits.length()-1;i>=0;i--) {
	     int index = bits.length()-i-1;
	     if(bits[i]=='1')  {
			value += pow(2.0,(double)index); 
		 }
    }  
    return value;
}


void reverseBitsToInt(string &bits)  {
	int count = 1;
	for(int i=1;i<bits.length();i++)  {
	   if(bits[i-1]==bits[i])  {
		   count++;
	   }
	   else {
	     cout<<"  "<<count;
	     count=1;
       }
    }
 return ;  
}

bool foundOrNot(int noOfOnes,int valueGreaterThanB)  {
    string temp = convertIntToString(valueGreaterThanB);
    int noOfOnesLocal = numberOfOnes(temp);
    if(noOfOnesLocal==noOfOnes)  {
        cout<<"greater than B = "<<valueGreaterThanB<<"\n";
        cout<<"temp = "<<temp;
        cout<<"noOfOnesLocal = "<<noOfOnesLocal;
	    reverseBitsToInt(temp);
		return true;
	}
return false;
}

int main()  {
	int N;
	string bits = "";
	int noOfOnes;
	int valueGreaterThanB;
	bool notFound = false;
	cin>>N;
	inputVector(N);
	
	for(int i=0;i<N;i++)  {
	   bits = bits+valueToString(i,v[i]);
    }
    
    cout<<bits;
    noOfOnes = numberOfOnes(bits);
    valueGreaterThanB = convertStringToInt(bits);
   
   valueGreaterThanB+1;
    while(!notFound)  {
	  notFound = foundOrNot(noOfOnes,valueGreaterThanB); 	
      valueGreaterThanB+=1;
    }
  return 0;  
}




