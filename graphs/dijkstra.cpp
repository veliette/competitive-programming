#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int, const vector<vector<pair<int, int>>>&);

const long long INF = LLONG_MAX;

int main() {
	int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    int u, v, w;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s, t;
    cin >> s >> t;

    vector<long long> resultado = dijkstra(s, adj);

    if (resultado[t] == INF) {
        cout << -1;
    } else {
        cout << resultado[t];
    }
    
    return 0;
}

vector<long long> dijkstra(int origen, const vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(adj.size(), INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[origen] = 0;
    pq.push({0, origen});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
