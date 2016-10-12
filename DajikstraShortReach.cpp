/*          DAJIKDTRA SHORT REACH - HACKER RANK            */
#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;


//  CLASS - Edge      //
class Edge {
  public:
    int node,weight;
    Edge(int node,int weight);
    int getNodeNumber();
    int getNodeWeight();
};


Edge::Edge(int node,int weight)  {
  this->node = node;
  this->weight = weight;
}

int Edge::getNodeNumber()  {
  return this->node;
}

int Edge::getNodeWeight()  {
  return this->weight;
}



//  CLASS GRAPH      
class Graph {
  public:
  vector< list<Edge> >adj;
  vector<bool>visited;
  vector<int>weights;
  int nodes,edges;
  Graph(int nodes,int edges);  
  void insertNode(int start,int end,int weight);
  void showAdjList();
  void shortestPath(int start);
};


Graph::Graph(int nodes,int edges)  {
  this->nodes = nodes;
  this->edges = edges;
  for(int i=0;i<nodes;i++)  {
     list<Edge> li;
     visited.push_back(false);
     weights.push_back(-1);
     adj.push_back(li);
  }
}

void Graph::insertNode(int start,int end,int weight)  {
  adj[start-1].push_back(Edge(end,weight));
//  adj[end-1].push_back(Edge(start,weight));
}

void Graph::showAdjList()  {
  int count=1;
  for(std::vector< list<Edge> >::iterator vecItr=adj.begin();vecItr!=adj.end();vecItr++)  {
     list<Edge>li = *vecItr;
     cout<<"\n"<<count;
     for(std::list<Edge>::iterator itrList=li.begin();itrList!=li.end();itrList++)  {
        Edge e = *itrList;
        cout<<"-> ("<<e.getNodeNumber()<<","<<e.getNodeWeight()<<")";
     } 
  }
}

void Graph::shortestPath(int start)  {
  queue<Edge>q;
  int length;
  visited[start-1] = true;
  q.push(Edge(start,0));
  while(!q.empty())  {
    Edge e = q.front();
    int str = e.getNodeNumber();
    cout<<"\n"<<str<<"weight =  "<<e.getNodeWeight()<<"\n";
    length = e.getNodeWeight();
    list<Edge>li = adj[str-1];
    for(std::list<Edge>::iterator itr=li.begin();itr!=li.end();itr++)  {
       Edge tempEdge = *itr;
       if(visited[tempEdge.getNodeNumber()-1]==false)  {
           visited[tempEdge.getNodeNumber()-1] = true;
           q.push(Edge(tempEdge.getNodeNumber(),tempEdge.getNodeWeight()+length));
       }
    }
    q.pop();
  }
}


int main()  {
   Graph g(4,4);
   g.insertNode(1,2,24);
   g.insertNode(1,4,20);
   g.insertNode(3,1,3);
   g.insertNode(4,3,12);
   g.showAdjList();
   cout<<"\nShortest Path\n";
   g.shortestPath(1);
  return 0;
}


