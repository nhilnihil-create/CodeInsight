#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int tn;
int t[400005];

void modify(int p){
    for(t[p+=tn]=1;p>1; p>>=1)
        t[p>>1] = t[p]+t[p^1];
}

int query(int l, int r){
    int ans = 0;
    for(l+=tn,r+=tn;l<r;l>>=1,r>>=1){
        if(l&1)
            ans+=t[l++];
        if(r&1)
            ans+=t[--r];
    }
    return ans;
}

int main(){
    ll k;
    int n;
    scanf("%d%lld",&n,&k);
    tn = n+1;
    vector<ll> a(n,0);
    for(int i = 0; i<n; i++)
        scanf("%lld",&a[i]);
    vector<pair<ll,int>> avec;
    avec.push_back({0,0});
    ll pref = 0;
    for(int i = 0; i<n; i++){
        pref += a[i];
        avec.push_back({pref-(k*(i+1)),i+1});
    }
    sort(avec.begin(),avec.end());
    vector<int> ainv(n+1,0);
    for(int i = 0; i<tn; i++)
        ainv[avec[i].second] = i;
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        modify(ainv[i-1]);
        ans+=query(0,ainv[i]);
    }
    printf("%lld\n",ans);
    return 0;
}