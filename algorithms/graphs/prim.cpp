#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n);
    vector<bool> visited(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int seleccionados = 0;
    long long costo = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [peso, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        seleccionados++;
        costo += peso;

        for (auto [v, w] : adj[u]) {
            if (!visited[v])
                pq.push({w, v});
        }
    }

    if (seleccionados == n) 
        cout << costo;
    else
        cout << "IMPOSIBLE";

    return 0;
}
