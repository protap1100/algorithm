#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge, query;
    cin >> node >> edge >> query;
    long long int adj_mat[node + 5][node + 5];
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
            {
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }
    while (edge--)
    {
       long long int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b],c);
        adj_mat[b][a] = min(adj_mat[a][b],c);
    }

    for (int k = 0; k < node; k++)
    {
    }

    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                {
                    if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    while (query--)
    {
        int source, dst;
        cin >> source >> dst;
        if (adj_mat[source][dst] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_mat[source][dst] << endl;
        }
    }

    return 0;
}