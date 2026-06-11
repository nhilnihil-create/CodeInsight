#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(n); i++)
using namespace std;
using ll = long long;

int dp[2][5005];
int good[5005];

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    
    ll cumsum[n + 1];
    cumsum[0] = 0;
    rep(i, n) cumsum[i + 1] = cumsum[i] + a[i];

    vector<ll> threshold(n);
    rep(i, n) threshold[i] = max((ll)0, (ll)k - cumsum[i]);

    reverse(a.begin(), a.end());
    reverse(threshold.begin(), threshold.end());
    
    int now, prev;
    dp [0][0] = dp[1][0] = 1;
    rep(i, n)
    {
        now = i % 2;
        prev = (i + 1) % 2;
        rep(j, k)
        {
            if (dp[prev][j] == 0) 
                continue;
            
            dp[now][j] = dp[prev][j];
            if (j + a[i] < k)
                dp[now][j + a[i]] = 1;

            if (j + a[i] >= threshold[i]) 
                good[i] = 1;

            // cout << i << ' ' << j << ' ' << threshold[i] << ' ' << j + a[i] << ' ' << k << endl;
        }
    }

    int ans = n;
    rep(i, n)
        if (good[i] == 1) 
            ans --;
    
    cout << ans << endl;

    return 0;
}