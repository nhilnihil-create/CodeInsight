//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    map<ll,ll> mp1,mp;
    REP(i,n){
        ll x;
        cin >> x;
        mp1[x]++;
        mp[x%m]++;
    }
    ll ans = 0;
    ans += mp[0]/2;
    mp[0]%=2;
    for(ll i=1;i<m-i;++i){
        ll t = min(mp[i],mp[m-i]);
        ans += t;
        mp[i] -= t;
        mp[m-i] -= t;
    }
    if(m%2==0){
        ans += mp[m/2]/2;
        mp[m/2]%=2;
    }
    for(ll i=1;i<=100000;++i){
        ll t = min(mp[i%m]/2, mp1[i]/2);
        ans += t;
        mp[i%m] -= t*2;
    }
    cout << ans << endl;
    return 0;
}