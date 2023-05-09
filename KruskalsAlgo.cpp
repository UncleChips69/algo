#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int>&parent ,vector<int>&rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

bool cmp(vector<int>a,vector<int>b)
{
    return a[2]<b[2];
}
int findParent(vector<int>&parent,int i)
{
    if(parent[i]==i) return i;

    return parent[i]=findParent(parent,parent[i]);

}

void unionSet(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findParent(parent,u);
    v=findParent(parent,v);

    if(rank[u] < rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}

int MST(vector< vector<int> >&edge,int n)
{
    sort(edge.begin(),edge.end(),cmp);
    // cout<<"\n sorted\n";
    // for(auto it:edge)
    // {
    //     for(auto x:it) cout<<x<<" ";
    //     cout<<endl;
    // }

    vector <int> parent(n);
    vector<int> rank(n);

    makeSet(parent,rank,n);

    int weight=0;
    cout<<"\n\nu\tv \t weight\n";
    for(int i=0;i<edge.size();i++)
    {
        int u=findParent(parent,edge[i][0]);
        int v=findParent(parent,edge[i][1]);
        int w=edge[i][2];

        if(u!=v)
        {
            weight+=w;
            unionSet(u,v,parent,rank);
            cout<<u<< " -->   "<<v<< "   = = = "<<w<<endl;
        }
    }

    return weight;
}

int main()
{
     int n;
    cout<<"No. of vertices-->";
    cin >> n;
    int e;
    cout<<"\nNo. of Edges-->";
    cin >> e;
    cout<<endl;
    cout<<"start node , end node , node weight \n";
    vector< vector<int> >edge;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);
        edge.push_back(temp);
    }
    
   int k=MST(edge,n);
   
   cout<<"\t \n Weight of MST--> "<<k<<"\n";

}

// vertices -9
// edges-14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 5 4
// 2 8 2
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 8 6
// 6 7 1
// 7 8 7

