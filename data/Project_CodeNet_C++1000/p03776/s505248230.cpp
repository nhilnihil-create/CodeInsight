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

int64 comb(int64 n, int64 r){
    double retval = 1;
    r = min(r, n-r);
    REP(i,r){
        retval *= (n - i);
        retval /= (i + 1);
    }
    return (int64)(retval + 1e-2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n,a,b;
    cin >> n >> a >> b;
    map<int32,int32> v;
    REP(i,n){
        int32 vi;
        cin >> vi;
        v[vi]++;
    }
    if(v.rbegin()->second >= a){
        cout << fixed << setprecision(6) << (double)(v.rbegin()->first) << endl;
        int64 ans2 = 0;
        FOR(i,a,min(v.rbegin()->second, b) + 1){
            ans2 += comb(v.rbegin()->second, i);
            // cout << i << " " << comb(v.rbegin()->second, i) << " " << ans2 << endl;
        }
        cout << ans2 << endl;
        return 0;
    }
    double ans = 0;
    int32 cnt = a;
    for(auto i = v.rbegin(); i != v.rend(); i++){
        if(i->second < cnt){
            ans += i->first * i->second;
            cnt -= i->second;
        }else{
            ans += i->first * cnt;
            ans /= a;
            cout << fixed << setprecision(6) << ans << endl;
            cout << comb(i->second, cnt) << endl;
            return 0;
        }
    }
    return 0;
}