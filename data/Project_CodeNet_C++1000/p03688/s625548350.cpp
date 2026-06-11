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
    int a[100010];
    rep(i, N) cin >> a[i];
    sort(a, a + N, greater<int>());
    int cnt1 = 0, cnt2 = 0;
    rep(i, N) {
        if (a[0] == a[i]) cnt2++;
        else cnt1++;
    }
    if (abs(a[N - 1] - a[0]) > 1) {cout << "No" << endl; return 0;}
    if (a[N - 1] == N - 1) {cout << "Yes" << endl; return 0;}

    int k = N - a[0];
    //cout << k + 1 << " " << k * 2 << endl;
    if (k + 1 <= cnt2 && cnt2 <= k * 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    //cout << cnt2 << " " << cnt1 << endl;



    return 0;
}
// a b c d e
// 4 4 4 4 4

// a a b c d
// 4 4 3 3 3

// a a a b c
// 3 3 3 2 2

// a a b b c
// 3 3 3 3 2

// a a a b b
// 2 2 2 2 2

// a a a a b
// 2 2 2 2 1

// a a a a a
// 1 1 1 1 1

// a a a b c d

// a a b b c d
// 4 4 4 4 3 3

// a a b b c c
// 3 3 3 3 3 3

// a a a b b b
// 2 2 2 2 2 2

// a a a a a b
// 2 2 2 2 2 1