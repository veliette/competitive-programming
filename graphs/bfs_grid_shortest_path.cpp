#include <bits/stdc++.h>
using namespace std;

int bfs(pair<int, int>, const vector<string>&);

int main() {
	int n, m;
    cin >> n >> m;

    vector<string> mapa(n);

    for (int i = 0; i < n; i++) {
        cin >> mapa[i];
    }

    for (int i = 0; i < mapa.size(); i++) {
        for (int j = 0; j < mapa[0].size(); j++) {

            if (mapa[i][j] == 'A') {

                cout << bfs({i, j}, mapa);

                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}

int bfs(pair<int, int> inicio, const vector<string>& mapa) {
    int n = mapa.size();
    int m = mapa[0].size();

    vector<vector<int>> dist(n, vector<int> (m, -1));
    queue<pair<int, int>> q;

    int cambioY[] = {-1, 1, 0, 0};
    int cambioX[] = {0, 0, -1, 1};

    q.push(inicio);
    dist[inicio.first][inicio.second] = 0;

    int fila, columna;

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            fila = u.first + cambioY[i];
            columna = u.second + cambioX[i];

            if (fila < 0 || columna < 0 || fila >= n || columna >= m) {
                continue;
            }

            if (mapa[fila][columna] != '#' && dist[fila][columna] == -1) {
                q.push({fila, columna});
                dist[fila][columna] = dist[u.first][u.second] + 1;

                if (mapa[fila][columna] == 'B') {
                    return dist[fila][columna];
                }
            }
        }
    }

    return -1;
}
