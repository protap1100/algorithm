#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int levelArr[1005];
int parentArr[1005];
void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis[src] = true;
    levelArr[src] = 0;
    // parentArr[src] = -1; Na korleo hobe korleo hobe etar man already -1
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
                parentArr[child] = par;
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
    memset(parentArr, -1, sizeof(parentArr));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
    vector<int> path;
    int node2 = dst;
    while (node2 != -1)
    {
        path.push_back(node2);
        node2 = parentArr[node2];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << endl;
    }

    return 0;
}