#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int main(){
    int n, m;
    cin >> n >> m;
    long long x[n], y[m];
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < m; i++) cin >> y[i];
    long long sum1 = 0, sum2 = 0;
    for(int k = 1; k <= n; k++){
        sum1 += (k - 1) * x[k-1] - (n - k) * x[k-1];
        sum1 %= mod;
    }
    for(int k = 1; k <= m; k++){
        sum2 += (k - 1) * y[k-1] - (m - k) * y[k-1];
        sum2 %= mod;
    }
    cout << (sum1 * sum2) % mod << endl;
    return 0;
}