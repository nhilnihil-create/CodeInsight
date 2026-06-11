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
    int32 n;
    cin >> n;
    vector<int32> a(n, 1);
    vector<int32> b(n, 1);
    REP(i,n){
        int32 p;
        cin >> p;
        p--;
        a[p] += i;
        b[p] += i;
    }
    FOR(i,1,n){
        a[i] += a[i-1];
    }
    FORR(i,n-2,0){
        b[i] += b[i+1];
    }
    REP(i,n)cout << a[i] << " ";
    cout << endl;
    REP(i,n)cout << b[i] << " ";
    cout << endl;
    return 0;
}