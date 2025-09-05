#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[1005];
int dis[1005];
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;
    pQue.push({0, src});
    dis[src] = 0;
    while (!pQue.empty())
    {
        pair<int, int> par = pQue.top();
        pQue.pop();
        int par_node = par.second;
        int par_dis = par.first;
        // cout << par_node << endl;
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pQue.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        // adj_list[b].push_back({a, c});
    }
    for (int i = 0; i < node; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);
    for (int i = 0; i < node; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
    return 0;
}