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
    int n; cin >> n;
    int A[100010];
    rep(i, n) cin >> A[i];
    int state = 0;
    int ans = 1;
    rep(i, n - 1) {
        if (state == 0 && A[i] == A[i + 1]) continue;
        if (state == 0 && A[i] < A[i + 1]) state = 1;
        else if (state == 0 && A[i] > A[i + 1]) state = -1;
        else if (state == 1 && A[i] > A[i + 1]) {state = 0; ans++;}
        else if (state == -1 && A[i] < A[i + 1]) {state = 0; ans++;}
    }
    cout << ans << endl;

    return 0;
}
