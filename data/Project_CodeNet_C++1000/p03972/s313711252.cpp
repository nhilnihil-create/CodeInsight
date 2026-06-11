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
    
    int w,h;
    cin >> w >> h;
    vector<pair<int,int>> al;
    rep(i,w){
        int p;cin >> p;
        al.pb(MP(p,1));
    }
    rep(i,h){
        int p;cin >> p;
        al.pb(MP(p,0));
    }
    SORT(al);
    int ans = 0;
    int hp = h+1;
    int wp = w+1;
    for(int i = 0;i < w+h;i++){
        if(al[i].se == 1){
            ans += hp*al[i].fi;
            wp--;
        }else{
            ans += wp*al[i].fi;
            hp--;
        }
    }
    cout << ans << endl;

    
    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://codefestival_2016_qualB.contest.atcoder.jp/tasks/codefestival_2016_qualB_c
