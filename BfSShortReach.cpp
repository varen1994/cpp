#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph  {
  public:
   int N;
   vector< list<int> > obj;
   vector<bool>status;
   vector<int>distance;
       Graph( int N );
       int start;
       void insertNode(int start,int end);
       void breadthFirstTraversal(int start);
       void showDistance();
};

Graph::Graph( int N )  {
   this->N = N;
   for(int i=0;i<N;i++)  {
       list<int>l;
       status.push_back(false);  
       obj.push_back(l);
       distance.push_back(-1);
   }
}

void Graph::insertNode(int start,int end)  {
  obj[start-1].push_back(end);
}

void Graph::breadthFirstTraversal(int start)  {
   queue<int>q;
   this->start = start;
   q.push(start);
   int count=1;
   status[start-1] = true;
   while(!q.empty())  {
      list<int>l = obj[start-1];
      for(std::list<int>::iterator itr= l.begin();itr!=l.end();itr++)  {
          if(!status[*itr])  {
             q.push(*itr); 
             distance[*itr] = count*6;
          }
          count++;
       }
   }
}

void Graph::showDistance()  {
  for(int i=0;i<distance.size();i++)  {
      if(this->start!=i+1)  {
          cout<<distance[i]<<" ";
       }
   }
}


int main()  {
   int Test,nodes,edges,startfrom;
  // cin>>Test;
  // Graph *g = new Graph[Test];
  
  // for(int i=0;i<Test;i++)  {
    cin>>nodes;
    Graph gra(nodes);
     cin>>edges;
     while(edges--)  {
          int start,end;
          cin>>start>>end;
          gra.insertNode(start,end);
    }
    cout<<"start from =";
    cin>>startfrom;
    gra.breadthFirstTraversal(startfrom);
    gra.showDistance();
     // g[i] = gra;
  // }

  // for(int i=0;i<Test;i++)  {
  //     Graph gra = g[i];
  //     gra.showDistance();
  //    cout<<"\n"; 
  // } 
  return 0;
}
