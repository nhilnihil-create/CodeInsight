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
    int f[N] = {0};
    int d = 0;
    FOR(i,0,N-1){ 
        int a; cin >> a;
        ++f[a];
        d = max(d,a);
    }
    int c = (d+1)/2;

    //cout << c << " " << d << endl;
    bool rip = 0;
    FOR(i,1,c-1) rip |= (f[i] > 0);
    FOR(i,c,d) rip |= (f[i] == 0);
    rip |= ((d&1) == 0 ? (f[c] != 1) : (f[c] != 2));

    cout << (rip ? "Impossible" : "Possible");
}

