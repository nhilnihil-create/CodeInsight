#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
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
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C;
    cin >> A >> B >> C;
    int cnt = 0;
    while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
        int nextA = (B / 2 + C / 2);
        int nextB = (C / 2 + A / 2);
        int nextC = (A / 2 + B / 2);
        if(nextA == A && nextB == B && nextC == C) {
            cout << -1 << endl;
            return 0;
        }
        A = nextA, B = nextB, C = nextC;
        cnt++;
    }
    cout <<cnt << endl;

    return 0;
}
