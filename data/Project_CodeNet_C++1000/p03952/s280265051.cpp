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
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == 2 * N - 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int order[200010];
    rep(i, N * 2 - 1) order[i] = (N + i + 1) % (N * 2 - 1) + 1;
    x -= 2;
    rep(i, N * 2 - 1) {
        cout << order[(x + i) % (N * 2 - 1)] << endl;
    }

    return 0;
}
//     2
//   3 2 2
// 5 3 1 2 4

//       2
//     3 2 2    
//   5 3 2 2 4
// 7 5 3 1 2 4 6


//        3
//      5 3 1
//    6 5 3 1 2
//  6 7 5 3 1 2 4  

//        5
//      6 5 3
//    6 6 5 3 2
//  4 6 7 5 3 1 2 

//       4
//     3 4 5
//   2 3 4 5 6
// 1 2 3 4 5 6 7

//       2
//     6 2 2
//   6 6 2 2 3
// 5 6 7 1 2 3 4


//