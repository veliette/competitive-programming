#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x);
void unite(vector<int>& parent, vector<int>& sz, int x, int y);

int main() {
	int n, m;
    cin >> n >> m;

    vector<tuple<long long, int, int>> edges(m);
    vector<int> parent(n, -1);
    vector<int> sz(n, 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        edges[i] = {w, u, v};
    }

    sort(edges.begin(), edges.end());

    int seleccionados = 0;
    long long costo = 0;

    for (auto [w, u, v] : edges) {
        if (find(parent, u) != find(parent, v)) {
            unite(parent, sz, u, v);
            seleccionados++;
            costo += w;

            if (seleccionados == n - 1)
                break;
        }
    }

    if (seleccionados == n - 1)
        cout << costo;
    else
        cout << "IMPOSIBLE";

    return 0;
}

int find(vector<int>& parent, int x) {
    if (parent[x] == -1)
        return x;

    parent[x] = find(parent, parent[x]);

    return parent[x];
}

void unite(vector<int>& parent, vector<int>& sz, int x, int y) {
    int a = find(parent, x);
    int b = find(parent, y);

    if (a == b)
        return;

    if (sz[a] > sz[b]) {
        parent[b] = a;
        sz[a] += sz[b];
    } else {
        parent[a] = b;
        sz[b] += sz[a];
    }
}
