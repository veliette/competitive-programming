#include <bits/stdc++.h>
using namespace std;

vector<int> kahn(const vector<vector<int>>&, vector<int>&);

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

    vector<int> orden = kahn(adj, indegree);

    if (orden.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << orden[i] << ' ';
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}

vector<int> kahn(const vector<vector<int>>& adj, vector<int>& indegree) {
    vector<int> orden;
    queue<int> q;

    for (int i = 0; i < adj.size(); i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        orden.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    return orden;
}
