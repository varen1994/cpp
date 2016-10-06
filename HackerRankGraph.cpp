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
  
  vector<int>relatedValues;
  
  public:
  int start;
  Graph(int N);   // constructor 
  void statusFill(int N);
  void makeAllVisitedFalse();
  void insertNode(int start,int end);
  void showAdjencyList();
  void fillWithMinusOne(int N);
  void breadthFirstTraversal(int start,int count);
  void showRelatedNodesDistance();
};

void Graph::makeAllVisitedFalse()  {
  for(int i=0;i<status.size();i++)  {
    status[i] = false;
  }
}


void Graph::fillWithMinusOne(int N)  {
  for(int i=0;i<N-1;i++)  {
    relatedValues.push_back(-1);
  }
}

/******* Deapth First Traversal ************
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
void Graph::breadthFirstTraversal(int start,int count)  {
    Q.push(start);
   cout<<"rec ="<<start<<"\n";
    if(!status[start-1] && this->start!=start)  {
       cout<<start<<"   distance ="<<count*6<<"\n";
    }
    vector<int>v = V[start-1];
      if(Q.size()  && status[start-1]==false)  {
        
         for(int io=1;io<v.size();io++)  {
               if(status[v[io]-1]==false)  {
                   status[v[io]-1] = true;
                   cout<<v[io]<<"   distance ="<<count*6<<"\n";
                   Q.push(v[io]);          
               }  
          }
          Q.pop();
          status[start-1] = true;  
          breadthFirstTraversal(Q.front(),count+1); 
       }
       else {
             Q.pop();
       }
}

  
void Graph::showRelatedNodesDistance()  {
  for(int i=0;i<relatedValues.size();i++)  {
     cout<<relatedValues[i];
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
  fillWithMinusOne(N);
}


void Graph::statusFill(int N)  {
  for(int i=0;i<N;i++)  {
    status.push_back(false);
  }
}

int main()  {
  Graph g(5);
  g.insertNode(1,2);
  g.insertNode(1,3);
  g.insertNode(2,4);
  g.insertNode(4,5);
  g.showAdjencyList();
  cout<<"\n****** Deapth First Traversal******* \n";
  g.start = 1;
  g.breadthFirstTraversal(1,1);
  g.showRelatedNodesDistance();
  return 0;
}


