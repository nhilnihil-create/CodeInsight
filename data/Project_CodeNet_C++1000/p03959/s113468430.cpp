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

int n;

signed main(){

    cin >> n;
    int t[100010];
    int a[100010];
    rep(i,n)cin >> t[i];    
    rep(i,n)cin >> a[i];
    int tt[100010]= {0};    
    int aa[100010]= {0};   

    for(int i = 1;i < n;i++){
        if(t[i-1] < t[i])tt[i] = 1;
    }
    for(int i = 1;i < n;i++){
        if(a[i-1] > a[i])aa[i-1] = 1;
    }
    tt[0] = 1;
    aa[n-1] = 1;
    
    int ans = 1;
    for(int i = 0;i < n;i++){
        if(tt[i] == 1 && aa[i] == 1){
            if(t[i] != a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(tt[i] == 1 && aa[i] == 0){
            if(t[i] > a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(tt[i] == 0 && aa[i] == 1){
            if(t[i] < a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(tt[i] == 0 && aa[i] == 0){
            ans *= min(t[i],a[i]);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;   
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://abc061.contest.atcoder.jp/tasks/abc061_d
