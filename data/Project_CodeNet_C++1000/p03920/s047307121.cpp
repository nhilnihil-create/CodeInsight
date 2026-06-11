#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repq(i,a,n) for(int i=a; i<=n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 2000000000
#define int long long int

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

int k, n;
int a[5000010];

bool d(int mid) {
    if(a[mid] >= k) return true;
    else return false;
}

signed main() {
    cin >> n;
    rep(i,0,5000010) {
        if(i == 0) a[i] = 0;
        else a[i] = i + a[i-1];
        // cout << a[i] << endl;
    }

    k = n;
    while(1) {
        // cout << k << endl;
        if(k <= 0) break;
        int ub = n+1, lb = 0;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(d(mid)) ub = mid;
            else lb = mid;
        }
        cout << ub << endl;
        k -= ub;
    }
    return 0;
}