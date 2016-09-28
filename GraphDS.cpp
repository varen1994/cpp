/*********************************************/
/*      GRAPH DS                             */
/********************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Graph  {
  vector< vector<int> >V;
  stack<int>S;
  vector<bool>status;
  public:
  Graph(int N);   // constructor 
  void statusFill(int N);
  void makeAllVisitedFalse();
  void insertNode(int start,int end);
  void showAdjencyList();
  void deapthFirstTraversal(int start);
  void breadthFirstTraversal(int start);
};

void Graph::makeAllVisitedFalse()  {
  for(int i=0;i<status.size();i++)  {
    status[i] = false;
  }
}

/******* Deapth First Traversal ************/
void Graph::deapthFirstTraversal(int start)  {
  S.push_back(start);
  vector<int>v = V[start-1];
 
  if(S.size())  {
    cout<<S[0]<<"\t";
    status[S[0]] = true;
       S.pop_back();
         for(int io;io<v.size();io++)  {
           if(status[v[io]]==false)  {
               status[v[io]] = true;
               deapthFirstTraversal(S[0]);
            } 
         }
   }
}

/******* Breadth First Traversal ***********/
void Graph::breadthFirstTraversal(int start)  {
 cout<<" Breadth First Traversal \n";




}

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
  statusFill(N);
}


void Graph::statusFill(int N)  {
  for(int i=0;i<N;i++)  {
    status.push_back(false);
  }
}

int main()  {
  Graph g(4);
  g.insertNode(1,2);
  g.insertNode(1,3);
  g.insertNode(1,4);
  g.insertNode(2,4);
  g.showAdjencyList();
  cout<<"\n****** Deapth First Traversal******* \n";
  g.deapthFirstTraversal(2); 
  return 0;
}


