#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x);
void unite(vector<int>& parent, vector<int>& sz, int x, int y);
void dfs(const vector<vector<pair<int, long long>>>& tree, vector<vector<int>>& up, 
    vector<vector<long long>>& mx, vector<int>& depth, int u, int p, long long w);
long long minimax(vector<vector<int>>& up, vector<vector<long long>>& mx, vector<int>& depth, 
    const int LOG, int u, int v);


int main() {
    int n, m;
    cin >> n >> m;

    // Vectores para MST
    vector<tuple<long long, int, int>> edges;
    vector<int> parent(n, -1);
    vector<int> sz(n, 1);
    vector<vector<pair<int, long long>>> tree(n);

    // Por cada M aristas
    for (int i = 0; i < m; i++) {
        long long w;
        int u, v;
        cin >> u >> v >> w;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    // Construimos MST con Kruskal
    int seleccionados = 0;

    for (auto [w, u, v] : edges) {
        if (find(parent, u) != find(parent, v)) {
            unite(parent, sz, u, v);

            tree[u].push_back({v, w});
            tree[v].push_back({u, w});

            seleccionados++;
        }
    }

    // Comprobamos MST
    if (seleccionados != n-1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    // Calcular el logaritmo base 2 de n
    int LOG = 1;

    while ((1LL << LOG) <= n) {
        LOG++;
    }

    // Vectores para DFS
    vector<vector<int>> up(n, vector<int>(LOG));
    vector<vector<long long>> mx(n, vector<long long>(LOG));
    vector<int> depth(n);

    int q, raiz = find(parent, 0);
    cin >> q;

    // Inicializar up y mx con DFS, llenar depth
    depth[raiz] = 0;
    dfs(tree, up, mx, depth, raiz, raiz, 0);

    // Llenar up y mx con Binary Lifting
    for (int i = 1; i < LOG; i++) {
        for (int u = 0; u < n; u++) {
            up[u][i] = up[up[u][i-1]][i-1];
            mx[u][i] = max(mx[u][i-1], mx[up[u][i-1]][i-1]);
        }
    }

    // Por cada Q consultas
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        cout << minimax(up, mx, depth, LOG, u, v) << '\n';
    }

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

void dfs(const vector<vector<pair<int, long long>>>& tree, vector<vector<int>>& up, 
    vector<vector<long long>>& mx, vector<int>& depth, int u, int p, long long w) {

    up[u][0] = p;
    mx[u][0] = w;

    for (auto [v, peso] : tree[u]) {
        if (v == p)
            continue;

        depth[v] = depth[u] + 1;
        dfs(tree, up, mx, depth, v, u, peso);
    }
}

long long minimax(vector<vector<int>>& up, vector<vector<long long>>& mx, vector<int>& depth, 
    const int LOG, int u, int v) {

    long long ans = 0;

    // Igualar profundidades
    if (depth[u] < depth[v])
        swap(u, v);

    int distancia = depth[u] - depth[v];

    for (int j = LOG-1; j >= 0; j--) {
        if (distancia & (1LL << j)) {
            ans = max(ans, mx[u][j]);
            u = up[u][j];
        }
    }

    if (u == v)
        return ans;

    // Subir ambos nodos mientras sus ancestros sean diferentes
    for (int j = LOG-1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            ans = max(ans, mx[u][j]);
            ans = max(ans, mx[v][j]);

            u = up[u][j];
            v = up[v][j];
        }
    }

    ans = max(ans, mx[u][0]);
    ans = max(ans, mx[v][0]);

    return ans;
}
