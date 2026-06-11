#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
int n, m;
vector<lint> x;
lint MOD = 1000000007;

lint calc(vector<lint> &vec)
{
    lint ans = 0;
    lint N = vec.size();
    for (lint i = 1; i < N; i++)
    {
        lint diff = (vec[i] - vec[i - 1]) % MOD;
        ans += diff * i * (N - i);
        ans %= MOD;
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    x.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    lint ans = calc(x);
    x.resize(m);
    for (int i = 0; i < m; i++) cin >> x[i];
    ans *= calc(x);
    cout << ans % MOD << endl;
}