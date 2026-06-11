#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int n, m; cin >> n >> m;
    ll a[51]; INITA(a, 0, 50, 0);
    ll b[51]; INITA(b, 0, 50, 0);
    ll c[51]; INITA(c, 0, 50, 0);
    ll d[51]; INITA(d, 0, 50, 0);
    REP(i, n) { cin >> a[i] >> b[i]; }
    REP(i, m) { cin >> c[i] >> d[i]; }
    REP(i, n) {
        ll min_diff = 10e14;
        int min_idx = 0;
        REP(j, m) {
            ll diff = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (diff < min_diff) {
                min_diff = diff;
                min_idx = j;
            }
        }
        cout << min_idx + 1 << endl;
    }
    return 0;
}