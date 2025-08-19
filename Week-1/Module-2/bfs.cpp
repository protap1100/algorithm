#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis[src] = true;
    while (!que.empty())
    {
        int par = que.front();
        que.pop();
        // print the children;
        cout << par << " ";
        // pushing the children
        for (int child : adj_list[par])
        {
            if (vis[child] == false)
            {
                que.push(child);
                vis[child] = true;
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
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    bfs(0);
    return 0;
}