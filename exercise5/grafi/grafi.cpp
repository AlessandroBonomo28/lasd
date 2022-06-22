

#include "../stack/lst/stacklst.hpp"


#include "../queue/lst/queuelst.hpp"

#include <iostream>
using namespace std;
/*
// ESEMPIO CON 5 VERTICI
const int vertex= 5;

int adj[vertex][vertex]={{1,1,0,0,0},
                        {0,1,1,1,0},
                        {0,0,1,0,1},
                        {0,0,0,1,1},
                        {0,0,1,1,1}};
                         
  

int status [vertex]={0,0,0,0,0};
 
/* ************************************************************************** */

// ESEMPIO CON 7 VERTICI
const int vertex= 7;

int adj[vertex][vertex]={{0,1,1,0,0,0,0},
                        {0,0,0,1,1,0,0},
                        {0,0,0,0,0,1,1},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0}};
                         
  
  // 0 = non visited (white), 1 = visited (black), 2 = come back (grey)
int status [vertex]={0,0,0,0,0,0,0};
/* ************************************************************************** */
char AdrToVertex(int i) // CODIFICA VISUALE DEI VERTICI
{
    // Decommenta per usare la codifica 1 2 3 ...
    return (char)(i+49); 
    // Decommenta per usare la codifica A B C ...
    //return (char)(i+65); 
}
void ResetStatus()
{
  for(int i=0;i<vertex;i++)
    status[i] = 0;
}
lasd::StackLst<int> GetAdj(int i)
{
  lasd::StackLst<int> stk = lasd::StackLst<int>();
  for (int j=0; j<vertex; j++)
    if (adj[i][j]==1 && j!= i)
      stk.Push(j);

  return stk;
}
void PrintAdj(int i)
{
  lasd::StackLst<int> s = GetAdj(i);
  if(s.Empty())
  {
    cout << "No adjacent vertex for "<<AdrToVertex(i) << endl;
    return;
  }
  cout<< "Adjacent vertex of "<<AdrToVertex(i)<<": ";
  while (!s.Empty())
  {
    cout << AdrToVertex(s.TopNPop()) << " ";
  }
  cout << endl;
}
void DFSPreOrder()
{
  cout<<"DFS pre order:"<<endl;
  lasd::StackLst<int> stk = lasd::StackLst<int>();

  for (int i=0; i<vertex; i++)
  {
    if (status[i]==0)
    {
      stk.Push(i);
      while (!stk.Empty())
      {
        int i = stk.TopNPop();
        if (status[i]==0)
        {
          status[i]=1;
          cout << AdrToVertex(i) << " ";
          lasd::StackLst<int> s = GetAdj(i);
          while (!s.Empty())
          {
            int j = s.TopNPop();
            if (status[j]==0)
              stk.Push(j);
          }
        }
      }
    }
  }
  cout<<endl;
}
void DFSPostOrder()
{
  cout<<"DFS post order:"<<endl;
  lasd::StackLst<int> stk = lasd::StackLst<int>();
  for (int i=0; i<vertex; i++)
  {
    if (status[i]==0)
    {
      stk.Push(i);
      while (!stk.Empty())
      {
        int i = stk.TopNPop();
        if (status[i]==0 )
        {
          lasd::StackLst<int> s = GetAdj(i);
          if(s.Empty())
          {
            status[i]=1;
            cout << AdrToVertex(i) << " ";
          }
          else
          {
            status[i]=2;
            stk.Push(i);
            while (!s.Empty())
            {
              int j = s.TopNPop();
              if (status[j]==0  )
                stk.Push(j);
            }
            
          }
        }
        else if(status[i]==2)
        {
          status[i]=1;
          cout << AdrToVertex(i) << " ";
        }
      }
    }
  }
  cout<<endl;
}
void BFS()
{
  cout<<"BFS:"<<endl;
  lasd::QueueLst<int> que = lasd::QueueLst<int>();
  for (int i=0; i<vertex; i++)
  {
    if (status[i]==0)
    {
      que.Enqueue(i);
      while (!que.Empty())
      {
        i = que.HeadNDequeue();
        if (status[i]==0)
        {
          status[i]=1;
          cout << AdrToVertex(i) << " ";
          lasd::StackLst<int> s = GetAdj(i);
          while (!s.Empty())
          {
            int j = s.TopNPop();
            if (status[j]==0)
              que.Enqueue(j);
          }
        }
      }
    }
  }
  cout<<endl;
}

int main() 
{
  for(int i=0;i<vertex;i++)
    PrintAdj(i);
  
  DFSPreOrder();
  ResetStatus();

  DFSPostOrder();
  ResetStatus();

  BFS();
  ResetStatus();
  return 0;
}

