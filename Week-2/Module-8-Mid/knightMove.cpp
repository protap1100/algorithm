#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
vector<pair<int, int>> d = {{2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> que;
    que.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!que.empty())
    {
        pair<int, int> par = que.front();
        que.pop();
        int par_x = par.first;
        int par_y = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_x + d[i].first;
            int cj = par_y + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                que.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_x][par_y] + 1;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj;
        cin >> di >> dj;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);
        cout << level[di][dj] << endl;
    }
    return 0;
}