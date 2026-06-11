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
    int n,t;
    cin >> n >> t;
    map<int,int> m;

    int min = INF;
    //int mx =  0;
    rep(i,n){
        int a;
        cin >> a;
        if(min >= a || i == 0){
            min = a;
            //mx = a;
        }else{
            //mx = max(a,mx);
            m[a-min]++;
        }
    }
    int ans = 0;
    int M = 0;
    for(auto x:m){
        if(M < x.fi){
            M = x.fi;
            ans = x.se;
        }
    }
    cout << ans << endl;
    

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc060.contest.atcoder.jp/tasks/arc060_a