#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 1LL << 62
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

struct bit {
    vector<ll> v; // 部分和をbitで管理 仮想配列はa[1...n]
    bit(int n){ // bit(int n) : v(n + 1) {}
        v.resize(n + 1);
    }
    
    ll sum(int i){ // 仮想配列a[1]~a[i]の和を求める
        ll ret = 0;
        for(; i > 0; i -= i & -i){ // i & -i: iの1が立っている最高位bitをの2^を返す
            ret += v[i];
        }
        return ret;
    }
    
    void add(int i, ll w) { // index:iにwを加える
        for (; i < v.size(); i += i & -i) {
            v[i] += w;
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> S(N + 1);
    rep(i, N) {
        cin >> S[i + 1];
        S[i + 1] -= K;
        S[i + 1] += S[i];
    }
    
    vector<ll> T = S;
    sort(all(T));
    map<ll, int> M;
    rep(i, N + 1) {
        if (i && T[i] == T[i - 1]) continue;
        M[T[i]] = i + 1;
    }
    
    bit B(N + 1);
    B.add(M[0], 1);
    ll ans = 0;
    rep(i, 1, N + 1) {
//        cout << M[S[i]] << ":" <<  B.sum(M[S[i]]) << endl;
        ans += B.sum(M[S[i]]);
        B.add(M[S[i]], 1);
    }

    output(ans);
    
    
    return 0;
}
