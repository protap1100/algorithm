#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int dis[1005];
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<Edge> edge_list;
    for (int i = 0; i < edge; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    int src;
    cin >> src;
    for (int i = 1; i <= node; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    for (int i = 1; i <= node - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    bool neg_cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            neg_cycle = true;
            break;
        }
    }
    if (neg_cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        for (int i = 1; i <= node; i++)
        {
            if (dis[i] == INT_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[i] << endl;
        }
    }

    return 0;
}
