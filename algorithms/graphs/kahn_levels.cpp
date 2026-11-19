#include <bits/stdc++.h>
using namespace std;

int kahn(const vector<vector<int>>&, vector<int>&, vector<int>&);

int main() {
	int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    int u, v;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> orden;

    int niveles = kahn(adj, indegree, orden);

    if (orden.size() == n) {
        cout << niveles;
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}

int kahn(const vector<vector<int>>& adj, vector<int>& indegree, vector<int>& orden) {
    queue<int> q;
    int niveles = 0;

    for (int i = 0; i < adj.size(); i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cantidad = q.size();
        niveles++;

        for (int i = 0; i < cantidad; i++) {
            int u = q.front();
            q.pop();

            orden.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }
    }

    return niveles;
}
