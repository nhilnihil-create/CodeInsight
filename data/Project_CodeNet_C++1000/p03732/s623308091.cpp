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
    ll n,wb;
    cin >> n>>wb;
    vll w(n),v(n);
    REP(i,n){
        cin >> w[i] >> v[i];
    }
    vvll val(4);
    REP(i,n){
        val[w[i]-w[0]].pb(v[i]);
    }
    REP(i,4){
        sort(rALL(val[i]));
    }
    vvll sval(4,vll(n+1));
    REP(i,4){
        if(!val[i].empty()){
            sval[i][0]=0;
            for(int j=0;j<(int)val[i].size();j++){
                sval[i][j+1]=sval[i][j]+val[i][j];
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<=(ll)val[0].size();i++){
        for(ll j=0;j<=(ll)val[1].size();j++){
            for(ll k=0;k<=(ll)val[2].size();k++){
                for(ll l=0;l<=(ll)val[3].size();l++){
                    if(w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l<=wb){
                        ans = max(ans,sval[0][i]+sval[1][j]+sval[2][k]+sval[3][l]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}