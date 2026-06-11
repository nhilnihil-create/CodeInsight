#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

template <typename T> T inf;
template <> constexpr int inf<int> = 1e9;
template <> constexpr ll inf<ll> = 1e18;

int main() {
    int N;
    cin >> N;
    vector<double> x(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    vector<double> y(N - 1);
    for(int i = 0; i + 1 < N; ++i) {
        y[i] = x[i + 1] - x[i];
    }
    ll M, K;
    cin >> M >> K;
    vector<int> a(M);
    for(int i = 0; i < M; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> sw(N - 1);
    for(int i = 0; i < N - 1; ++i) {
        sw[i] = i;
    }
    auto res = sw;
    for(int i = 0; i < M; ++i) {
        swap(sw[a[i] - 1], sw[a[i]]);
    }
    while(K > 0) {
        if(K & 1) {
            auto nxt = res;
            for(int i = 0; i < N - 1; ++i) {
                nxt[i] = res[sw[i]];
            }
            res = move(nxt);
        }

        auto nxt_sw = sw;
        for(int i = 0; i < N - 1; ++i) {
            nxt_sw[i] = sw[sw[i]];
        }
        //for(auto s : sw) {
        //    cout << s << ' ';
        //}
        //cout << endl;
        sw = move(nxt_sw);
        K >>= 1;
    }

    vector<double> pos(N);
    pos[0] = x[0];
    for(int i = 1; i < N; ++i) {
        pos[i] = pos[i - 1] + y[res[i - 1]];
    }

    for(auto p : pos) {
        cout << fixed << setprecision(12) << p << endl;
    }
}
