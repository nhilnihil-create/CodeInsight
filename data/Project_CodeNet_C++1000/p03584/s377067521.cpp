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
int n,k;
signed main(){
    cin >> n >> k;
    int a[100010];
    int b[100010];
    rep(i,n) cin >> a[i] >> b[i];

    int ans = 0;
    rep(i,n){
        int c = 1;
        rep(j,30){
            if((!(k&(1LL<<j))) && (a[i]&(1LL<<j)))c = 0;
        }
        if(c == 1)ans += b[i];
    }
    for(int i = 30; i >= 0;i--){
        if(k&(1LL<<i)){
            int ans1 = 0;
            int x = k;
            x &= ~(1LL<<i);
            rep(ii,n){
                int c = 1;
                for(int j = i;j <= 30;j++){
                    if(!(x&(1LL<<j)) && (a[ii]&(1LL<<j)))c = 0;
                }
                if(c == 1)ans1 += b[ii];
            }
            ans = max(ans,ans1);
        }
    }
    
    cout << ans << endl;
    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 