#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int a[110];
    rep(i, N) cin >> a[i];
    sort(a, a + N);
    rep(i, N - 1) {
        if (a[i + 1] - a[i] > 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if (a[0] * 2 != a[N - 1] && a[0] * 2 != a[N - 1] + 1) {
        cout << "Impossible" << endl;
    } else if (a[N - 1] % 2 == 0 && a[0] == a[1]) {
        cout << "Impossible" << endl;
    } else if (a[N - 1] % 2 == 1 && a[0] == a[2]) {
        cout << "Impossible" << endl;
    }  else {
        cout << "Possible" << endl;
    }

    return 0;
}
