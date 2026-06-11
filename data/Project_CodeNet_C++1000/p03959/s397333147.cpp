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
    int n;
    cin >> n;
    vint conf(n,0);
    vint mount(n,0);
    {
        int pre=0;
        REP(i,n){
            int h;
            cin >> h;
            mount[i]=h;
            if(h!=pre){
                conf[i]=1;
            }
            pre=h;
        }
    }
    {
        int pre=0;
        vint a(n);
        REP(i,n)cin >> a[i];
        for(int i=n-1;i>=0;--i){
            int h = a[i];
            if(conf[i]==1){
                if(h<mount[i] || (pre!=h&&h!=mount[i])){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(h!=pre){
                    conf[i]=1;
                    if(h>mount[i]){
                        cout << 0 << endl;
                        return 0;
                    }
                    mount[i]=h;
                }else{
                    mount[i] = min(mount[i], h);
                }
            }
            pre=h;
        }
    }
    ll ans = 1;
    REP(i,n){
        if(conf[i]==0){
            ans *= (ll)mount[i];
            ans = FIX(ans);
        }
    }
    cout << ans << endl;
    return 0;
}