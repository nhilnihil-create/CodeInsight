#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;



ll INF=LLONG_MAX;
int main()
{
    // input
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // solve
    ll ans=INF;
    for(ll bit=0; bit<(1<<(n-1)); bit++){
        vector<int> tmp(0);
        for(int i=0; i<n-1; i++){
            if(bit&(1<<i)){
                tmp.emplace_back(i);
            }
        }
        if(tmp.size()<k-1) continue;
        ll ans_tmp=0;
        ll nmax=a[0];
        for(int i=1; i<n; i++){
            if(find(tmp.begin(),tmp.end(),i-1)!=tmp.end()){
                if(a[i]<=nmax) {ans_tmp+=(nmax-a[i]+1); nmax++;}
                else nmax=a[i];
            }
            else{
                nmax = max(nmax, a[i]);
            }
        }
        ans=min(ans,ans_tmp);
    }
    // output
    cout << ans << endl;
    return 0;
}