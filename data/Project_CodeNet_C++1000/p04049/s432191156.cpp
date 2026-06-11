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
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;
int MOD = 1000000007;
vector<int> G[2010];
int used[2010][2010] = {0};
int cnt[2010] = {0};
int n,k;
void dfs1(int p,int d,int i){
    if(used[i][p] == 1)return;
    used[i][p] = 1;    
    if(d > k/2)cnt[i]++;
    for(auto x:G[p])dfs1(x,d+1,i);
    return;
}
void dfs2(int p,int d,int i){
    used[i][p] = 1;    
    if(d > k/2)cnt[i]++;
    for(auto x:G[p]) if(used[i][x] == 0)dfs2(x,d+1,i);
    return;
}
signed main(){
    cin >> n >> k;
    pair<int,int> edge[2010];
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        G[b-1].push_back(a-1);
        G[a-1].push_back(b-1);
        edge[i] = MP(a-1,b-1);
    }
    if(k%2 == 0){
        rep(i,n){
             dfs1(i,0,i);
        }
        int mini = INF;
        rep(i,n)mini = min(mini,cnt[i]);
        cout << mini << endl;
    }else{
        rep(i,n-1){
            used[i][edge[i].fi] = 1;
            used[i][edge[i].se] = 1;
            dfs2(edge[i].fi,0,i);
            dfs2(edge[i].se,0,i);
        }
        int mini = INF;
        rep(i,n-1)mini = min(mini,cnt[i]);
        cout << mini << endl;
    }
    
    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://agc026.contest.atcoder.jp/tasks/agc026_c
// rm -r -f test;oj dl http://abc107.contest.atcoder.jp/tasks/abc107_b