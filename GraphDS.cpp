/*********************************************/
/*      GRAPH DS                             */
/********************************************/

#include<iostream>
#include<vector>

using namespace std;

class Graph  {
  vector< vector<int> >V;
  public:
  Graph(int N);   // constructor 
  void insertNode(int start,int end);
  void showAdjencyList();
};

void Graph::insertNode(int start,int end)  {
   V[start-1].push_back(end);
}

void Graph::showAdjencyList()  {
   for(int it = 0;it<V.size();it++)  {
      vector<int>v = V[it];
      for(int io = 0;io<v.size();io++)  {
         cout<<v[io]<<"->";    
      } 
     cout<<"\n";
   }  
}

Graph::Graph(int N)  {
  for(int i=1;i<=N;i++)  {
     vector<int> v;
     v.push_back(i);
     V.push_back(v);
  } 
}


int main()  {
  Graph g(4);
  g.insertNode(1,2);
  g.insertNode(1,3);
  g.insertNode(1,4);
  g.insertNode(2,4);
  g.showAdjencyList();
  return 0;
}


