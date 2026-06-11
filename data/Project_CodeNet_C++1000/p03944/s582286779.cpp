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
    int w, h, n; cin >> w >> h >> n;
    int m[101][101];
    REP(i, 100) {
        REP(j, 100) {
            m[i][j] = 0;
        }
    }
    REP(k, n) {
        int x, y, a; cin >> x >> y >> a;
        REP(i, h) {
            REP(j, w) {
                if ((a == 1) && (j < x)) {
                    m[i][j] = 1;
                } else if ((a == 2) && (j >= x)) {
                    m[i][j] = 1;
                } else if ((a == 3) && (i < y)) {
                    m[i][j] = 1;
                } else if ((a == 4) && (i >= y)) {
                    m[i][j] = 1;
                }
            }
        }
    }
    int res = 0;
    REP(i, h) {
        REP(j, w) {
            // cout << m[i][j];
            if (m[i][j] == 0) {
                res++;
            }
        }
        // cout << endl;
    }
    cout << res << endl;
    return 0;
}