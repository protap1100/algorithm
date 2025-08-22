#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<int> adj_list[node];
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u;
        cin >> u;
        if (adj_list[u].empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            sort(adj_list[u].rbegin(), adj_list[u].rend());
            for (int v : adj_list[u])
            {
                cout << v << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
