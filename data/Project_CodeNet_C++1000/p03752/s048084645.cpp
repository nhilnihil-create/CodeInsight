#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
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
/*----------------------------------------------------------------*/

// int MOD = 998244353;
int MOD = 1000000007;

/*----------------------------------------------------------------*/
signed main(){

    int n,k;
    cin >> n >> k;
    vll a(n);
    rep(i,n)cin >> a[i];

    int ans = INF;
    for(int bit = 0;bit <(1LL<<n);bit++){
        int maxi = 0;
        int cost = 0;
        int cnt = 0;
        rep(i,n){
            if(maxi < a[i]){
                cnt++;
                maxi = a[i];
            }else if(bit&(1LL<<i)){
                cnt++;
                maxi = maxi+1;
                cost += maxi-a[i];
            }
            if(cnt >= k)break;
        }
        if(cnt >= k)ans = min(ans,cost);
    }

    cout << ans << endl;
    
	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=c++14 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://pakencamp-2019-day3.contest.atcoder.jp/tasks/pakencamp_2019_day3_c
// rm -r -f test;oj dl https://s8pc-4.contest.atcoder.jp/tasks/s8pc_4_b