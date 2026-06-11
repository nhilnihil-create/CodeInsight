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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, L;
    cin >> N >> L;
    int a[100010];
    rep(i, N) cin >> a[i];
    int idx = -1;
    rep(i, N - 1) {
        if(a[i] + a[i + 1] >= L) idx = i;
    }
    if(idx == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    REP(i, 0, idx - 1) {
        cout << i + 1 << endl;
    }
    RREP(i, N - 2, idx + 1) {
        cout << i + 1 << endl;
    }
    cout << idx + 1 << endl;


    return 0;
}
