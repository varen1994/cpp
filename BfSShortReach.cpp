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
      list<int>l = obj[q.front()-1];
      for(std::list<int>::iterator itr= l.begin();itr!=l.end();itr++)  {
          if(!status[*itr-1])  {
             q.push(*itr); 
             this->distance[*itr-1] = count*6;
             status[*itr-1] = true;
          }
      }
     count++;
     q.pop();
   }
}

void Graph::showDistance()  {
   for(int i=1;i<=distance.size();i++)  {
      if(this->start!=i)  {
          cout<<distance[i-1]<<" ";
       }
   }
}

int main()  {
   int Test,nodes,edges,startfrom;
   cin>>Test;
   vector<Graph> graVec;
 
   for(int i=0;i<Test;i++)  {
	    cin>>nodes;
	    cin>>edges;
	    Graph gra(nodes);
	     while(edges--)  {
		  int start,end;
		  cin>>start>>end;
		  gra.insertNode(start,end);
	    }
	    cin>>startfrom;
	    gra.breadthFirstTraversal(startfrom);
            graVec.push_back(gra);
    }


   for(std::vector<Graph>::iterator itr=graVec.begin();itr!=graVec.end();itr++)  {
	   Graph gra = *itr;
           gra.showDistance();
           cout<<"\n"; 
   }

   return 0;
}
