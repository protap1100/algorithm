#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];

int main()
{
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    int query;
    cin >> query;
    while (query--)
    {
        int u, v;
        cin >> u >> v;
        bool found = false;
        if (u == v)
        {
            found = true;
        }
        else
        {
            for (int child : adj_list[u])
            {
                if (child == v)
                {
                    found = true;
                    break;
                }
            }
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
