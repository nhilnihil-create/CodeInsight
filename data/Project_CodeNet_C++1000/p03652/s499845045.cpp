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
    int n,m;
    cin >> n >> m;
    int ans = n;
    vvint a(n,vint(m));
    REP(i,n) {
        REP(j,m) {
            cin >> a[i][j]; 
            a[i][j]--;
        }
    }
    vint sp(m,1);
    int rem = m;
    while(rem>=1){
        vint cnt2(m,0);
        REP(i,n){
            REP(j,m){
                if(sp[a[i][j]]==1){
                    cnt2[a[i][j]]++;
                    break;
                }
            }
        }
        int tmp = 0;
        REP(i,m){
            tmp = max(tmp,cnt2[i]);
        }
        ans = min(ans,tmp);
        vint cnt(m,0);
        REP(i,n){
            REP(j,m){
                if(sp[a[i][j]]==1){
                    cnt[a[i][j]]++;
                    break;
                }
            }
        }
        int t = -1;
        int c = -1;
        REP(i,m){
            if(cnt[i]>c){
                c=cnt[i];
                t=i;
            }
        }
        sp[t]=0;
        //cout << rem << " " << t << endl;
        rem--;
    }
    cout << ans << endl;

    return 0;
}