#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

	vector<vector<int>> precios(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> precios[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> (m));

    dp[0][0] = precios[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + precios[i][0];
    }
    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i-1] + precios[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = precios[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "Precio minimo: " << dp[n-1][m-1] << "\n\n";

    vector<pair<int, int>> camino(n+m-1);
    int pos = 0;

    for (int i = n-1, j = m-1; i + j >= 1; pos++) {
        camino[pos].first = i;
        camino[pos].second = j;
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else {
            if (dp[i-1][j] < dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    camino[pos].first = 0;
    camino[pos].second = 0;

    

    for (int i = camino.size()-1; i >= 0; i--) {
        cout << "(" << camino[i].first << ", " << camino[i].second << ")\n";
    }

    return 0;
}
