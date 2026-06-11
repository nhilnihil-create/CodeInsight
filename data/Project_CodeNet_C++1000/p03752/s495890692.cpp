#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll c(const vector<ll> &p, const vector<bool> &b) {
    ll h = p[0];
    ll res = 0;
    for (int i = 1; i < p.size(); i++)
    {
        if (b[i] == true)
        {
            if (p[i] <= h)
            {
                res += h - p[i] + 1;
                h++;
            }
        }
        h = max(h, p[i]);
    }
    return res;
}

ll calc(int n, int k, const vector<ll> &p) {
    vector<bool> b(n);
    for(int i = 0; i < k; i++) b[n - 1 - i] = true;
    ll m = LLONG_MAX;
    do {
        m = min(m, c(p, b));
    } while(next_permutation(b.begin(), b.end()));
    return m;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(auto &x: A) cin >> x;
    cout << calc(N, K, A) << endl;
}