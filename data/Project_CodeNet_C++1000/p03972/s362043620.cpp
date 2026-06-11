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
    ll w,h;
    cin >> w >> h;
    ll ans = 0;
    vector<pair<ll, int> > wh(w+h);
    REP(i,w){
        ll p;
        cin >> p;
        wh[i]=make_pair(p,0);
    }
    REP(i,h){
        ll q;
        cin >> q;
        wh[i+w] = make_pair(q,1);
    }
    ll wc = 0;
    ll hc = 0;
    sort(ALL(wh));
    REP(i,w+h){
        auto now = wh[i];
        if(now.se==0){
            ans+= (now.fi)*(h+1-hc);
            wc++;
        }else{
            ans+= (now.fi)*(w+1-wc);
            hc++;
        }
    }
    cout << ans << endl;

    return 0;
}