#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    ll N, L, T, gap = 0;
    cin >> N >> L >> T;
    vector<ll> p;
    rep(i, N) {
        int x, w;
        cin >> x >> w;
        ll pos = x + T*(w==1 ? 1 : -1);
        ll np = ((pos%L)+L)%L;
        gap += (pos > 0 ? pos / L : (pos - L + 1) / L);
        p.push_back(np);
    }
    //cout << gap << endl;
    sort(p.begin(), p.end());
    gap = ((gap%N)+N)%N;
    rep(i, N) {
        cout << p[(i + gap)%N] << endl;
    }
    return 0;
}
