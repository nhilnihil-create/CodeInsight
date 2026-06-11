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
typedef pair<int, int> P;

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[100010];
    rep(i, N) cin >> A[i];
    int ans = A[0] - 1;
    int k = 1;
    rep(i, N - 1) {
        //cerr << k << " " << A[i + 1] << " " << (A[i + 1] - 1) / k << " " << ans + (A[i + 1] - 1) / k << endl;
        ans += (A[i + 1] - 1) / (k + 1);
        if(A[i + 1] + 1 - k <= 2) {
            k = max(k, A[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
// 3 1 4 1 5 9 2 6 5 3 5 8 9 7 9
// 2 0 1 0 2 4 0 1 1 0 1 1 2 1 2 
// 