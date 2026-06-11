#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n, x;
    cin >> n >> x;
    if(x == 1 || x == 2 * n - 1){
        Yes(false);
        return 0;
    }
    Yes(true);
    if(n == 2){
        FOR(i,1,n*2)ANS(i);
        return 0;
    }

    if(x < n){
        int32 y = 2 * n - 3;
        REP(i,n-3){
            ANS(y);
            y--;
        }
        ANS(2 * n - 1);
        ANS(1);
        ANS(x);
        ANS(2 * n - 2);
        REP(i,n-2){
            if(y == x)y--;
            ANS(y);
            y--;
        }
    }else{
        int32 y = 3;
        REP(i,n-3){
            ANS(y);
            y++;
        }
        ANS(1);
        ANS(2 * n - 1);
        ANS(x);
        ANS(2);
        REP(i,n-2){
            if(y == x)y++;
            ANS(y);
            y++;
        }
    }
    return 0;
}