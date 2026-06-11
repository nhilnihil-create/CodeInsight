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
    int A, B;
    cin >> A >> B;
    A = (A + 11) % 13;
    B = (B + 11) % 13;
    if (A < B) {
        cout << "Bob" << endl;
    } else if (A > B) {
        cout << "Alice" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
