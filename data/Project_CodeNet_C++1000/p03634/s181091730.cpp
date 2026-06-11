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
    ll n;
    cin >> n;
    vector<vector<pair<ll,ll> > > nei(n);
    REP(i,n-1){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        nei[a].pb(make_pair(b,c));
        nei[b].pb(make_pair(a,c));
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    ll q,k;
    cin >> q >> k;
    k--;
    vll dis(n,LLINF);
    dis[k] = 0;
    pq.push(make_pair(0,k));
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        for(auto i : nei[p.se]){
            if(dis[i.fi]>dis[p.se]+i.se){
                dis[i.fi]=dis[p.se]+i.se;
                pq.push(make_pair(dis[i.fi], i.fi));
            }
        }
    }
    REP(i,q){
        ll x,y;
        cin >> x >> y;
        x--; y--;
        cout << dis[x]+dis[y] << "\n";
    }
    return 0;
}