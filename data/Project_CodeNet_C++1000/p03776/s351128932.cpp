#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int64_t nCk(int N, int K) {
    if(K < 0 || N < K) return 0;
    int64_t ret = 1;
    for(int i = 1; i <= K; ++i) {
        ret *= N--;
        ret /= i;
    }
    return ret;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<double> v(N);
    rep(i, 0, N) cin >> v[i];
    sort(v.begin(), v.end(), greater<double>());
    double sum = 0;
    rep(i, 0, A) sum += v[i];
    int X = 0;
    rep(i, 0, N) if(v[i] == v[A - 1]) X++;
    int64 ans = 0;
    if(v[0] == v[A - 1]) {
        rep(i, A, B + 1) ans += nCk(X, i);
    } else {
        int Y = 0;
        rep(i, 0, A) if(v[A - 1] == v[i]) Y++;
        ans = nCk(X, Y);
    }
    printf("%.10lf\n", sum / A);
    cout << ans << endl;
    return 0;
}
