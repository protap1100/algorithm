#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
vector<int> area;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;
    for (int i = 0; i < d.size(); i++)
    {
        int ci, cj;
        ci = si + d[i].first;
        cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            count += dfs(ci, cj);
    }
    return count;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(vis, false, sizeof(vis));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                int sz = dfs(i, j);
                area.push_back(sz);
            }
        }
    }
    sort(area.begin(), area.end());
    if (area.empty())
        cout << -1 << endl;
    else
    {
        cout << area[0] << endl;
    }
    return 0;
}