#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
    cin >> n >> m;

    vector<vector<long long>> adj(n, vector<long long>(n, LLONG_MAX));
    vector<bool> visited(n, false);
    vector<long long> dist(n, LLONG_MAX);

    for (int i = 0; i < m; i++) {
        long long w;
        int u, v;
        cin >> u >> v >> w;

        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    int menor = 0, seleccionados = 0;
    long long costo = 0;

    dist[menor] = 0;


    while (seleccionados < n) {
        if (menor == -1 || dist[menor] == LLONG_MAX)
            break;

        visited[menor] = true;

        costo += dist[menor];
        seleccionados++;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dist[i] = min(dist[i], adj[menor][i]);
        }

        menor = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (menor == -1 || dist[i] < dist[menor]))
                menor = i;
        }
    }

    if (seleccionados == n)
        cout << costo;
    else
        cout << "IMPOSIBLE";

    return 0;
}
