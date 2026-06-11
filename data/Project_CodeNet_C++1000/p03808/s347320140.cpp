#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int A[N]; ll S = 0; FOR(i,0,N-1) { cin >> A[i]; S += A[i]; }

    ll T = (ll)N*(N+1)/2;
    if (S % T != 0) { cout << "NO"; return 0; }
    S /= T;
    ll X = 0;
    FOR(i,0,N-1) {
        ll y = A[(i+1)%N]-A[i] - S;
        if (y > 0 || y%N != 0) { cout << "NO"; return 0; }
        y /= -N;
        X += y;
    }
    cout << (X == S ? "YES" : "NO");
}

