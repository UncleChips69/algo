#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V,  unordered_map<int,list< pair<int,int> > >&adj, int S)
{
    vector<int> dist(V+1, INT_MAX);
    vector<int>par(V+1,-1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[S] = 0;
    pq.push({S, 0});
    par[S]=-1;

    while (!pq.empty())
    {
        int node = pq.top().first;
        int dis = pq.top().second;

        pq.pop();

        for (auto it : adj[node])
        {
            int neighbour = it.first;
            int edgeW = it.second;

            if (dis + edgeW < dist[neighbour])
            {
                dist[neighbour] = dis + edgeW;
                par[neighbour]=node;
                pq.push({neighbour, dist[neighbour]});
            }
        }
    }

    cout<<"\nparent-->\n";
    for(int i=1;i<=V;i++)
    {
        cout<<par[i]<<" ";
    }
    cout<<endl;

    return dist;
}


int main()
{
    unordered_map<int,list< pair<int,int> > >adj;
// 5-->{6,7} , 
// 4-->{2,2} , {3,9} , {5,4} , 
// 3-->{6,6} , {5,3} , 
// 2-->{3,2} , 
// 1-->{2,8} , {4,3} , 

    int v;
    cout<<"vertices->";
    cin>>v;
    int e;
    cout<<"\nedges->";cin>>e;

    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,pow(wt,2)});
    }

    for(auto it:adj)
    {
        cout<<it.first<<"-->";
        for(auto i:it.second) cout<<"{"<<i.first<<","<<i.second<<"} , ";
        cout<<endl;
    }


vector<int>distFromSource=dijkstra(v,adj,1);

for(int i=1;i<=v;i++)
{
    // cout<<i<<"-->";
    cout<<distFromSource[i]<<" ";
}
    
}