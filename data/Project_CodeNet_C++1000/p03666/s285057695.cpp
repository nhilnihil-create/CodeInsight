#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

signed main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    vi cu(N), du(N), cd(N), dd(N);
    cu[0] = du[0] = cd[0] = dd[0] = A;

    rep(i, N) {
        int r = N-1-i;
        int hh, hl, lh, ll;
        hh = du[i] - r*C;
        hl = cu[i] - r*D;
        lh = cd[i] + r*D;
        ll = dd[i] + r*C;

        if(B<=hh && B>=hl) {
            cout << "YES" << endl;
            return 0;
        }
        if(B<=lh && B>=ll) {
            cout << "YES" << endl;
            return 0;
        }

        cu[i+1] = cu[i]+C;
        du[i+1] = du[i]+D;
        cd[i+1] = cd[i]-C;
        dd[i+1] = dd[i]-D;
    }

    cout << "NO" << endl;

    return 0;
}