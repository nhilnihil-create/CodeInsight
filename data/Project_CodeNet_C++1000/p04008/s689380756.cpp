#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> v(100010),rev(100010);
ll d[100010];

void depth(ll p,ll u,ll dist){
    d[p] = dist;
    for(auto i:v[p]){
        if(i != u){
            depth(i,p,dist+1);
        }
    }
}

ll n,k;
ll ans = 0;

void dfs(ll p,ll u,ll dist){
    d[p] = dist;
    if(dist == 1) return;
    for(auto i:v[p]){
        if(i != u){
            dfs(i,p,dist-1);
        }
    }
}

void merge(ll p,ll u,ll dist){
    if(dist == 1){
        dfs(p,-1,k);
        ans++;
        return;
    }
    for(auto i:rev[p]){
        if(i != u){
            merge(i,p,dist-1);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    cin>>n>>k;
    ll a[n];
    cin>>a[0];
    a[0]--;
    if(a[0]!=0){
        ans++;
        a[0] = 0;
    }
    for(ll i=1;i<n;i++){
        cin>>a[i];
        a[i]--;
        v[a[i]].push_back(i);
        rev[i].push_back(a[i]);
    }
    depth(0,-1,0);
    pair<ll,ll> p[n];
    for(ll i=0;i<n;i++){
        p[i] = make_pair(d[i],i);
    }
    sort(p,p+n,greater<pair<ll,ll>>());
    for(ll i=0;i<n;i++){
        ll j = p[i].second;
        if(d[j]>k){
            merge(j,-1,k);
        }
    }
    cout << ans << endl;
}