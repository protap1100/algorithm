#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int levelArr[1005];

void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis[src] = true;
    levelArr[src] = 0;
    while (!que.empty())
    {
        int par = que.front();
        que.pop();
        for (int child : adj_list[par])
        {
            if (vis[child] == false)
            {
                que.push(child);
                vis[child] = true;
                levelArr[child] = levelArr[par] + 1;
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
    memset(levelArr, -1, sizeof(levelArr));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
         cout << levelArr[dst] << endl;

    return 0;
}