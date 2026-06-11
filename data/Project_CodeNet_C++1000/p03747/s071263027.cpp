#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
    int N, L, T, cnt = 0;
    cin >> N >> L >> T;
    vector<int> p(N);
    for(int i = 0; i < N; ++i) {
        int X, W, a, b;
        cin >> X >> W;
        W = pow(-1, W - 1);
        a = W * T;
        b = (X + a) % L;
        p[i] = b < 0 ? b + L : b;
        cnt += a / L;
        a %= L;
        if(X + a >= L || X + a < 0)
            cnt += W;
        cnt %= N;
    }
    sort(p.begin(), p.end());
    cnt = cnt < 0 ? cnt + N : cnt;
    for(int i = cnt; i < N + cnt; ++i)
        cout << p[i % N] << endl;
}
