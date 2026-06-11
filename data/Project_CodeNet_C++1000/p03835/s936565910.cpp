#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define ll long long

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;
int main()
{
    ll k, s;
    ll ans = 0;
    cin >> k >> s;

    rep(h, k+1){
        rep(i, k+1){
            if (s - h - i <= k && s - h - i >= 0){
                ans++;
            }
        }
    }

    cout << ans << endl;
    
}
