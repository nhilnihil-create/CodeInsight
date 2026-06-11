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

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (((a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0)) && ((a == b) && (a == c))) {
        cout << -1 << endl;
    } else {
        int tot = 0;
        while ((a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0)) {
            int na = b / 2 + c / 2;
            int nb = a / 2 + c / 2;
            int nc = a / 2 + b / 2;
            a = na;
            b = nb;
            c = nc;
            tot++;
        }
        cout << tot << endl;
    }
    return 0;
}