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
    ll n; cin >> n;
    ll a[500010]; INITA(a, 0, 500000, -1);
    ll base = 250000;
    if (n % 2 == 0) {
        REP(i, n) {
            // 2: 2 1
            // 4: 4 2 1 3
            if (i % 2 == 0) {
                cin >> a[base+i/2];
            } else {
                cin >> a[base-(i+1)/2];
            }
        }
    } else {
        REP(i, n) {
            // 1: 1
            // 3: 3 1 2
            // 5: 5 3 1 2 4
            if (i % 2 == 0) {
                cin >> a[base-(i+2)/2];
            } else {
                cin >> a[base+(i-1)/2];
            }
        }
    }
    ll res = 0;
    REP(i, 500000) {
        if (a[i] != -1) {
            if (res != 0) {
                cout << " ";
            }
            cout << a[i];
            res++;
        }
    }
    cout << endl;
    return 0;
}