#include <bits/stdc++.h>
using namespace std;
char grid[10005][10005];
bool vis[10005][10005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
vector<int> area;

bool valid(int i, int j) {
    return !(i < 0 || i >= n || j < 0 || j >= m);
}

int bfs(int pi, int pj) {
    queue<pair<int,int>> q;
    q.push({pi, pj});
    vis[pi][pj] = true;
    int count = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.') {
                vis[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                int sz = bfs(i, j); 
                area.push_back(sz);
            }
        }
    }

    sort(area.begin(), area.end());
    if (area.empty())
        cout << -1 << endl;
    else
        cout << area[0] << endl;

    return 0;
}
