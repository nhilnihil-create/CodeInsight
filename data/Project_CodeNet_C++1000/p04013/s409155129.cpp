#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N = 53;
ll n,A,a[N];
ll dp[N][N][N*N];

ll rec(int i,int cnt,int cur) {
    if(i == n && A*cnt == cur && cnt>0)
        return 1;
    else if(i == n)
        return 0;
    ll& cache = dp[i][cnt][cur];
    if(cache != -1)
        return cache;
    ll ans = 0;
    ans += rec(i+1,cnt+1,cur+a[i]) + rec(i+1,cnt,cur);
    return cache = ans;
}

void solve(){
    cin >> n >> A;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i)
        cin >> a[i];
    cout << rec(0,0,0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

