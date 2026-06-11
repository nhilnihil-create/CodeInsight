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
    vector<int> p[100010];
    int used[100010] = {0};
    vector<int> g;
    vector<int> s;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        p[a].pb(b);
        p[b].pb(a);
        if(i == 0){
            s.pb(a);
            g.pb(b);
            used[a] = 1;
            used[b] = 1;
        }
    }
    int cnt = 2;
    int now = g[0];
    while(1){
        int c = 0;
        for(auto x:p[now]){
            if(used[x] == 0){
                c = 1;
                now = x;
                g.pb(x);
                used[x] = 1;
                cnt++;
                break;
            }
        }
        if(c == 0)break;
    }
    now = s[0];
    while(1){
        int c = 0;
        for(auto x:p[now]){
            if(used[x] == 0){
                c = 1;
                now = x;
                s.pb(x);
                used[x] = 1;
                cnt++;
                break;
            }
        }
        if(c == 0)break;
    }
    cout << cnt << endl;
    for(int i = s.size()-1;i >= 0;i--)cout << s[i] << " ";
    for(int i = 0;i < g.size();i++)cout << g[i] << " ";
    cout << endl;


    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://agc013.contest.atcoder.jp/tasks/agc013_b