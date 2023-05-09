#include <bits/stdc++.h>
using namespace std;
class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void primMST(unordered_map<int, list<pair<int, int>>> g, int n, int source)
{
    vector<int> key(n + 1, 100);
    vector<bool> inMst(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int src = source;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // if (inMst[u] == 1)
        // {
        //     continue;
        // }
        inMst[u] = 1;
        for (auto it : g[u])
        {
            int v = it.first;
            int w = it.second;
            //    cout<<v<<"   " <<w<<endl;
            //    cout<<inMst[v] << "     "    <<   key[v]<<"\n";
            if (inMst[v] == 0 && w < key[v])
            {
                key[v] = w;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
                //    cout<<parent[v]<<"  -- - -- -     "<<key[v];
            }
        }
    }

    cout << "node          parent    weight \t  \n";
    for (int i = 1; i <= n; ++i)
    {
        cout << i << "\t\t";
        cout << parent[i] << "\t";
        cout << key[i] << "\t \n";
        // cout << inMst[i] << "\n";
    }
    //    cout<<"i--"<<i <<" "<<parent[i]<< " - "<< i<<" \n";
}

int main()
{
    // int l = 1, u = 7;
    // int n= (rand() % (u - l + 1)) + l;
    // int randomE= (rand() % (10 - 18 + 1)) + 10;

    // int lb = n-1, ub = n-1+randomE;
    // int e=(rand() % (lb - ub + 1)) + lb;
    int n;
    cout<<"No. of vertices-->";
    cin >> n;
    int e;
    cout<<"\nNo. of Edges-->";
    cin >> e;
    cout<<endl;
    unordered_map<int, list<pair<int, int>>> g;
    cout<<"start node , end node , node weight \n";
    for (int i = 1; i <= e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        // u= (rand() % (ux - lx + 1)) + lx;
        // v= (rand() % (ux - lx + 1)) + lx;
        // while(u==v)
        // {
        // v= (rand() % (ux - lx + 1)) + lx;
        // }

        // wt= (rand() % (wux - wlx + 1)) + wlx;

        g[u].push_back(make_pair(v, wt));
        g[v].push_back(make_pair(u, wt));
    }
    // for(auto it : g)
    // {
    //     cout<<it.first<<" ----\n ";
    //     for(auto x :it.second) cout<<x.first<<" "<<x.second<<"\n";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        cout<<"\tFOR SOURCE --> "<<i<<endl;
        cout<<"\t_____________________\n";
        primMST(g, n, i);
        cout<<"\n\n";
    }
}


// No. of vertices-->9

// No. of Edges-->14

// start node , end node , node weight 
// 1 2 4
// 1 8 8
// 2 3 8
// 2 8 11
// 3 9 2
// 3 6 4
// 3 7 4
// 4 5 9
// 4 6 14
// 5 6 10
// 6 7 2
// 7 8 1
// 7 9 6
// 8 9 7