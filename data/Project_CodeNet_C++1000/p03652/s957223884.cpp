#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
 
using namespace std;
int MOD = 1000000007;

signed main(){

    int n,m;
    cin >> n >> m;
    queue<int> a[310];
    int used[310] = {0};
    int ans = 500;
    rep(i,n){
        rep(j,m){
            int v;
            cin >> v;
            a[i].push(v);
        }
    }

    rep(i,m){
        rep(j,n){
            while(used[a[j].front()] == 1)a[j].pop();
        }
        int cnt[310] = {0};
        rep(j,n) cnt[a[j].front()]++;
        int maxi = 0;
        int s = 0;
        for(int j = 1;j <= m;j++){
            if(maxi < cnt[j]){
                maxi = cnt[j];
                s = j;
            }
        }
        // for(int j = 1;j <= m;j++)cerr << cnt[j] << " ";
        // cerr << endl;
        // cerr << i << " " << maxi << endl;
        ans = min(ans,maxi);
        used[s] = 1;
    }
    cout << ans << endl;

    return 0;   
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://agc018.contest.atcoder.jp/tasks/agc018_b
// rm -r -f test;oj dl http://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_c