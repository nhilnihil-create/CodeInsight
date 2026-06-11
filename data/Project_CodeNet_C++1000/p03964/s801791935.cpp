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
    ll now = 0;
    ll tn=0;
    ll an=0;
    REP(i,n){
        ll t,a;
        cin >> t >> a;
        ll ok = (LLINF)/(t+a);
        ll ng = 0;
        while(abs(ok-ng)>1){
            ll mid = (ok+ng)/2;
            bool f = true;
            if(mid*(t+a)<now){
                f = false;
            }else{
                if(mid*t<tn||mid*a<an){
                    f = false;
                }
            }
            if(f){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        now = ok*(t+a);
        tn = ok*t;
        an = ok*a;
    }
    cout << now << endl;

    return 0;
}