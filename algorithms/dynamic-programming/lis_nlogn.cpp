#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> tails;
    vector<int> tailsIndex;
    vector<int> predecesor(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(tails.begin(), tails.end(), v[i]) - tails.begin();

        if (pos > 0) {
            predecesor[i] = tailsIndex[pos-1];
        }

        if (pos == tails.size()) {
            tails.push_back(v[i]);
            tailsIndex.push_back(i);
        } else {
            tails[pos] = v[i];
            tailsIndex[pos] = i;
        }
    }

    int k = tails.size();

    if (k == 0) {
        return 0;
    }

    vector<int> secuencia(k);

    for (int i = tailsIndex[k-1], pos = k-1; i != -1; i = predecesor[i], pos--) {
        secuencia[pos] = v[i];
    }

    for (int i = 0; i < k; i++) {
        cout << secuencia[i] << ' ';
    }

    return 0;
}
