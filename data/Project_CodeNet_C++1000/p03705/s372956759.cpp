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
    int N, A, B;
    cin >> N >> A >> B;
    if (A > B) {
        cout << 0 << endl;
        return 0;
    }
    if(N == 1) {
        if(A == B) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int lower = A * (N - 1) + B;
    int upper = A + B * (N - 1);
    cout << upper - lower + 1 << endl;

    return 0;
}