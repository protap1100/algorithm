#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, egde;
    cin >> node >> node;
    int adj_mat[node][node];
    memset(adj_mat, 0, sizeof(adj_mat));
    for (int m = 0; m < node; m++)
    {
        for (int n = 0; n < node; n++)
        {
            if (n == m)
            {
                adj_mat[m][n] = 1;
            }
        }
    }

    for (int i = 0; i < egde; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        // adj_mat[b][a] = 1; // Directed Graph
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}