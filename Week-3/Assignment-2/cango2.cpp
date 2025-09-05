#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, c;
    Edge(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int dis[1005];
vector<Edge> edge_list;
int node, edge;
bool bellman_ford(int src) {
    for (int i = 1; i <= node; i++) {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;

    for (int i = 1; i <= node - 1; i++) {
        for (auto ed : edge_list) {
            int a = ed.a, b = ed.b, c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }
    for (auto ed : edge_list) {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> node >> edge;
    while (edge--) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    int src;
    cin >> src;
    int tCase;
    cin >> tCase;

    if (!bellman_ford(src)) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }
    while (tCase--) {
        int dest;
        cin >> dest;
        if (dis[dest] == INT_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dis[dest] << endl;
        }
    }

    return 0;
}
