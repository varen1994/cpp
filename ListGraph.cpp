#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Edge {
  public:
   int end,weight;
    Edge(int end,int weight)  {
       this->end = end;
       this->weight = weight;
     }
};



class Graph {
  public:
  vector< list<Edge> > G;
  stack <int> dft;
  vector<bool>visited;
  Graph(int N);  
  void insertValue(int start,int end,int weight);
  void showAdjencyList();
  void depthFirstTraversal(int start,int distance);
};

Graph::Graph(int N)  {
   for(int i=0;i<N;i++)  {
      list <Edge> g;
      visited.push_back(false);
      G.push_back(g);
   }
}

void Graph::insertValue(int start,int end,int weight)  {
    Edge edge(end,weight);
    G[start-1].push_back(edge);  
}

void Graph::showAdjencyList() {
  int count = 1;
  for(std::vector< list<Edge> >::iterator itr=G.begin();itr!=G.end();itr++)  {
      list<Edge>e = *itr;
      cout<<count<<"    ";
      for(std::list<Edge>::iterator iter=e.begin();iter!=e.end();iter++)  {
         Edge e = *iter;  
         cout.width(10);  
         cout<<"<"<<e.end<<","<<e.weight<<">  "; 
     }
    cout<<"\n";
    count++;
  }
}

void Graph::depthFirstTraversal(int start,int distance) {
  
       dft.push(start-1);
       list<Edge>e = G[start-1];
       cout<<"start"<<start<<"weight"<<distance<<"\n";
       visited[start-1] =true;
          for(std::list<Edge>::iterator iter=e.begin();iter!=e.end();iter++)  {
              Edge e = *iter;  
              if(visited[e.end-1]==false)  {
                  depthFirstTraversal(e.end,distance+e.weight); 
              }
         }  
}

/****** MAIN *******/
   int main()  {
	Graph graph(5);
	graph.insertValue(1,2,10);
	graph.insertValue(1,3,5);
        graph.insertValue(1,5,2);
	graph.insertValue(2,1,1);
	graph.insertValue(2,4,11);
	graph.insertValue(3,2,90);
	graph.insertValue(4,4,100);
	graph.insertValue(4,5,121);
	graph.insertValue(5,1,6);
        graph.showAdjencyList(); 
        graph.depthFirstTraversal(1,0);  
  return 0;
  }
