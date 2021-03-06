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
  queue<int>Q;
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
  S.push(start);
  vector<int>v = V[start-1];
  if(v.size())  {
    cout<<S.top()<<"\t";
    status[S.top()] = true;
    S.pop();
         for(int io;io<v.size();io++)  {
           if(status[v[io]]==false)  {
               deapthFirstTraversal(v[io]);
            } 
         }
   }
}

/******* Breadth First Traversal ***********/
void Graph::breadthFirstTraversal(int start)  {
    Q.push(start);
    vector<int>v = V[start-1];
      cout<<Q.front()<<"\t";
      status[Q.front()] = true;
      Q.pop();
     if(!Q.empty())  {
           for(int io=1;io<v.size();io++)  {
            if(status[v[io]]==false)  {
               status[v[io]] = true; 
               Q.push(v[io]);          
            } 
         }
        deapthFirstTraversal(Q.back());
     }
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
  g.insertNode(2,3);
  g.insertNode(3,4);
  g.insertNode(3,1);
  g.insertNode(4,4);
  g.showAdjencyList();
  cout<<"\n****** Deapth First Traversal******* \n";
  g.breadthFirstTraversal(3);
  return 0;
}


