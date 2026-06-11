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
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    typedef tuple<ll, char> t;
    vector<t> v;
    v.push_back(make_tuple(q * 8, 'q'));
    v.push_back(make_tuple(h * 4, 'h'));
    v.push_back(make_tuple(s * 2, 's'));
    v.push_back(make_tuple(d * 1, 'd'));
    sort(v.begin(), v.end(),
        [](t const &lhs, t const &rhs) {
            if (get<0>(lhs) != get<0>(rhs)) return get<0>(lhs) < get<0>(rhs);
            if (get<1>(lhs) != get<1>(rhs)) return get<1>(lhs) < get<1>(rhs);
            return true;
        }
    );
    ll res = 0;
    REP(i, v.size()) {
        switch (get<1>(v[i])) {
            case 'q':
                if (n > 0) {
                    res += 4 * q * n;
                    n = 0;
                }
                break;
            case 'h':
                if (n > 0) {
                    res += 2 * h * n;
                    n = 0;
                }
                break;
            case 's':
                if (n >= 1) {
                    res += s * n;
                    n = 0;
                }
                break;
            case 'd':
                if (n >= 2) {
                    res += d * (n / 2);
                    if (n % 2 == 0)  {
                        n = 0;
                    } else {
                        n = 1;
                    }
                }
                break;
        }
        if (n == 0) {
            break;
        }
    }
    cout << res << endl;
    return 0;
}