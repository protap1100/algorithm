#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> movement = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int target_i, target_j;
bool found = false;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    if (grid[i][j] == '#')
    {
        return false;
    }
    return true;
}
void dfs(int si, int sj)
{
    if (si == target_i && sj == target_j)
    {
        found = true;
        return;
    }
    vis[si][sj] = true;

    for (auto mv : movement)
    {
        int ci = si + mv.first;
        int cj = sj + mv.second;

        if (valid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    int start_i = 0, start_j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start_i = i;
                start_j = j;
            }
            if (grid[i][j] == 'B')
            {
                target_i = i;
                target_j = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(start_i, start_j);

    if (found)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
