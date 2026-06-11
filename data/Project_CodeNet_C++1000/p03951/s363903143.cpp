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
    string S, T;
    cin >> S >> T;
    int len = 0;
    rep(i, N) {
        bool ok = true;
        rep(j, N - i) {
            if (S[i + j] != T[j]) ok = false;
        }
        if(ok) len = max(len, N - i);
    }
    cout << N * 2 - len << endl;
    return 0;
}
// abcd
//  bcde