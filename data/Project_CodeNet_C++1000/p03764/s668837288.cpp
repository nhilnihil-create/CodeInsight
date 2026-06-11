#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

int main(void) {
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> x(n), y(m);
    for(int i=0; i<n; i++) {
        cin >> x[i];
    }
    for(int j=0; j<m; j++) {
        cin >> y[j];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int64_t X =0;
    for(int i=0; i<n-1; i++) {
        X += (x[i+1] - x[i]) * (((i+1) * (n-1-i)) % MOD);
        X %= MOD;
    }
    int64_t Y = 0;
    for(int j=0; j<m-1; j++) {
        Y += (y[j+1] - y[j]) * (((j+1) * (m-1-j)) % MOD);
        Y %= MOD;
    }

    cout << X*Y%MOD << endl;
    return 0;
}
