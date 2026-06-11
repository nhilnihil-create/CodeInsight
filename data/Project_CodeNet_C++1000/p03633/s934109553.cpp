#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return GCD(b, a % b);
    }
}

ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

void vector_LCM(vector<ll> v) {
    if (v.size() == 1) {
        cout << v[0] << endl;
    } else {
        ll a, b;
        a = v[v.size() - 1];
        v.pop_back();
        b = v[v.size() - 1];
        v.pop_back();
        v.push_back(LCM(a, b));
        vector_LCM(v);
    }
}

int main() {
    int N;
    cin >> N;
    vector<ll> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector_LCM(T);

    return 0;
}
