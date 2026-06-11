#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
    vector<ll> a(n),imos(m+10,0);
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    ll cnt=0; // x=0 の時のコスト
    for(int i=1;i<n;i++){
        cnt += min((a[i]+m-a[i-1])%m, 1+a[i]);
        if(a[i-1]<a[i]){
            if(a[i]-a[i-1]>=2){
                imos[a[i-1]+1]++;
                imos[a[i]]--;
            }
        }
        else{
            imos[a[i-1]+1]++;
            imos[0]++;
            imos[a[i]]--;
        }
        mp[a[i]] += (a[i]+m-a[i-1])%m -1;
    }
    for(int i=1;i<=m;i++){
        imos[i] += imos[i-1];
    }
    ll res=cnt;
    for(int i=0;i<m-1;i++){
        cnt -= imos[i];
        cnt += mp[i];
        res=min(res,cnt);
    }
    cout<<res<<endl;
}
