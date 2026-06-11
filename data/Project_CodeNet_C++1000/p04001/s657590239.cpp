#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 1e5 + 5;
ll dp[maxn] , sum[maxn] , pre[maxn] , mu[maxn];
string a;
int main()
{
    ios::sync_with_stdio(false);
    cin >> a;
    int n = a.size();
    a = '#' + a;
    ll x = 0, y = 0;
    for (int i = 1 ; i <= n ; i++){
        int v = a[i] - '0';
        x = 10 * x + v;
        dp[i] = x;
        if (i != 1) {
            y = 10 * y + v;
            dp[i] += dp[1] + y;
        }
        if (i > 2){
            mu[i] = mu[i - 1] + (1 << (i - 2));
            sum[i] = (sum[i - 1]) * 10 + mu[i] * v;
            dp[i] += pre[i - 1] - pre[1] + sum[i];
        }
        pre[i] = pre[i - 1] + dp[i];
    }
    cout << dp[n] << endl;
    return 0;
}