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

int sum1[100010];
int sum2[100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    int q; cin >> q;
    rep(i, S.length()) {
        sum1[i + 1] += sum1[i] + (S[i] - 'A') + 1;
        sum2[i + 1] += sum2[i] + (T[i] - 'A') + 1;
    }
    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int len1 = sum1[b] - sum1[a - 1];
        int len2 = sum2[d] - sum2[c - 1];
        if (len1 % 3 == len2 % 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
