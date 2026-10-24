#include <bits/stdc++.h>
using namespace std;

int main() {
	int objetos, espacio;
    cin >> objetos >> espacio;

    vector<pair<int, int>> v(objetos);

    for (int i = 0; i < objetos; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> antes(espacio + 1, 0);
    vector<int> ahora(espacio + 1, 0);

    int peso, valor;

    for (int i = 1; i <= objetos; i++) {
        peso = v[i-1].first;
        valor = v[i-1].second;

        for (int j = 1; j <= espacio; j++) {
            if (j < peso) {
                ahora[j] = antes[j];
            } else {
                ahora[j] = max(antes[j], valor + antes[j-peso]);
            }
        }

        antes = ahora;
    }

    cout << ahora[espacio];
    
    return 0;
}
