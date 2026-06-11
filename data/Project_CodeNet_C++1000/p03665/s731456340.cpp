#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fact(ll x) {
    if (x == 1 || x == 0) {
        return 1;
    } else {
        return x * fact(x - 1);
    }
}

long long int combination(long long int n, long long int k) {
    vector<vector<long long int>> v(n + 1, vector<long long int>(n + 1, 0));
    for (long long int i = 0; i < n + 1; i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (long long int i = 1; i < n + 1; i++) {
        for (long long int j = 1; j < i; j++) {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }

    return v[n][k];
}

int main() {
    int N, P;
    cin >> N >> P;

    ll even = 0;
    ll odd = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }

    ll output = 0;
    if (P == 1) {
        for (ll i = 1; i <= odd; i += 2) {
            output += combination(odd, i);
        }
        output *= powl(2, even);
    } else {
        for (ll i = 0; i <= odd; i += 2) {
            output += combination(odd, i);
        }
        output *= powl(2, even);
    }

    cout << output << endl;

    return 0;
}
