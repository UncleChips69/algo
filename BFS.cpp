#include<bits/stdc++.h>
using namespace std;
void create_adjacency_list(int vertex,vector<pair<int,int>>&edges
,unordered_map<int,set<int>>&adj)
{
    cout<<"\nadjancency list for graph\n";
    for(auto it:edges)
    {
        adj[it.first].insert(it.second);
        adj[it.second].insert(it.first);
    }

    for(auto it:adj)
    {
        cout<<it.first<<"->";
        for(auto x:it.second) 
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void bfs(int vertex,unordered_map<int,set<int>>&adj
,vector<int>&BFS,int node,unordered_map<int,bool>&visit)
{
    BFS.clear();
    queue<int>q;
    q.push(node);
    visit[node]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        BFS.push_back(front);

        for(auto it:adj[front])
        {
            if(!visit[it])
            {
                q.push(it);
                visit[it]=1;
            }
        }
    }

    for(auto x:BFS) cout<<x<<" ";
}

int main()
{
    int vertex;
    cout<<"enter no. of vertices-->";cin>>vertex;
    vector<pair<int,int>>edges;
    int x,y;
    cout<<"enter edges , press -1 -1 to quit\t";
    cout<<"\t-- USE 0 BASED INDEXING ---\n";
    while(x!=-1 && y!=-1)
    {
        cin>>x;
        cin>>y;
        if(x!=-1 && y!=-1)
        edges.push_back(make_pair(x,y));
    }

    unordered_map<int,set<int>>adj;
    cout<<"\n\n";
    create_adjacency_list(vertex,edges,adj);

    vector<int>BFS;
    unordered_map<int,bool>visit;
    for(int i=0;i<vertex;i++)
    {
        BFS.clear();
        visit.clear();
    cout<<"\nBFS Traversal for root as "<< i << "-->";
    bfs(vertex,adj,BFS,i,visit);
    cout<<"\n";
    }
}