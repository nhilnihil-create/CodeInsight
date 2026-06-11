#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(int i = (int)m; i < (int)n; i++)
#define rep(i,n) REP(i,0,n)
#define rep2(i,n) REP(i,1,n+1)
#define rep3(i,n) REP(i,0,n+1)
#define REPM(i,m,n) for(int i = (int)m; i >= (int)n; i--)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define repll(i,n) REPLL(i,0,n)
#define repll2(i,n) REPLL(i,1,n+1)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define Size(s) (int) s.size()

//------------------------------------------------------

int main() {
    ll n;
    cin >> n;
    ll i = 1;
    while (n > 0) {
        if (i * (i + 1) / 2 >= n) {
            cout << i << endl;
            n -= i;
            i = 0;
        }
        i++;
    }

    return 0;
}