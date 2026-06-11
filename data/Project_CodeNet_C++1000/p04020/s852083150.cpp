#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5+5;
int n, a[N];
ll dp[2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0]/2;
    if(a[0]) dp[1]=(a[0]-1)/2;
    for(int i = 1; i < n; i++) {
        ll newdp[2];
        newdp[0]=0,newdp[1]=0;
        if(a[i]>=1) {
            newdp[1]=(a[i]-1)/2+max(dp[0],dp[1]);
        }
        if(a[i]>=2 && a[i-1]!=0) {
            newdp[1]=max(newdp[1], (a[i]-2)/2+dp[1]+1);
        }
        newdp[0]=a[i]/2+max(dp[0], dp[1]);
        if(a[i-1]!=0 && a[i]>=1) {
            newdp[0]=max(newdp[0], (a[i]-1)/2+dp[1]+1);
        }
        dp[0]=newdp[0];
        dp[1]=newdp[1];
    }
    cout << max(dp[0], dp[1]);
    return 0;
}