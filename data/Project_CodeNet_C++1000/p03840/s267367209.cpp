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

signed main(){
    int ai,ao,at,aj,al,as,az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;
    int ans = ao;
    if(ai%2 && aj%2 && al%2){
        ans += ai + aj + al;
    }else if(ai%2==0 && aj%2==0 && al%2==0){
        ans += ai + aj + al;
    }else if(ai<2 && aj<2 && al<2){
        ans += 0;
    }else{
        ans += ai + aj + al - 1;
    }
    cout << ans << endl;

    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d
// rm -r -f test;oj dl http://agc008.contest.atcoder.jp/tasks/agc008_c