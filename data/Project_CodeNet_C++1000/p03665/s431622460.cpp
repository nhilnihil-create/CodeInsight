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

ll comb(ll n, ll r) {
    ll res = 1;
    for(ll i=1; i<=r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    int n, p; cin >> n >> p;
    int a[51]; INITA(a, 0, 50, 0);
    int num_odd = 0;
    int num_even = 0;
    REP(i, n) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            num_even++;
        } else {
            num_odd++;
        }
    }
    ll res = 0;
    if (p == 1) {
        if (num_odd > 0) {
            res = pow(2, num_odd-1);
        } else {
            res = 0;
        }
        res *= pow(2, num_even);
    } else {
        if (num_odd > 0) {
            res = pow(2, num_odd-1);
        } else {
            res = 1;
        }
        res *= pow(2, num_even);
    }
    cout << res << endl;
    return 0;
}