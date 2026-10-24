#include <bits/stdc++.h>
using namespace std;

void bfs(int, vector<vector<int>>&);

int main() {
	int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0, adj);
}

void bfs(int inicio, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[inicio] = true;
    q.push(inicio);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << ' ';

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
