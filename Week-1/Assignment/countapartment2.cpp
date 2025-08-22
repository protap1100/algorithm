#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int n, m;
vector<pair<int, int>> movement = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    else
        return false;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + movement[i].first;
        int cj = sj + movement[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            count = count + dfs(ci, cj);
        }
    }
    return count;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    vector<int> apartment_sizes;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int size = dfs(i, j);
                apartment_sizes.push_back(size);
            }
        }
    }

    if (apartment_sizes.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(apartment_sizes.begin(), apartment_sizes.end());
        for (int sz : apartment_sizes)
        {
            cout << sz << " ";
        }
        cout << endl;
    }

    return 0;
}
