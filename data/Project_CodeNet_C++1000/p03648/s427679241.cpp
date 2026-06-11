#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int long long

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

typedef pair<int, int> pint;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front

#define MOD (1000 * 1000 * 1000 + 7)

signed main() {
    ll K;
    cin >> K;

    ll N = 50;
    cout << N << endl;

    vector<ll> a(N, N-1);

    REP(i, N) {
        a[i] += K / N;
    }

    int th = K%N;
    REP(i, N) {
        if (i < th) {
            a[i] += (N - th + 1);
        } else {
            a[i] -= th;
        }
    }

    REP(i, N) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}