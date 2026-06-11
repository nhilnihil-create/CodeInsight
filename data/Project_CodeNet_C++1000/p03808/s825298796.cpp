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
    int N; cin >> N;
    int A[100010];
    int B[100010];
    rep(i, N) cin >> A[i];
    int sum = 0;
    rep(i, N) sum += A[i];
    int num = 0;
    rep(i, N) num += i + 1;
    if(sum % num != 0) {
        cout << "NO" << endl;
        return 0;
    }
    rep(i, N) B[i] = A[(i + 1) % N] - A[i] - (sum / num);
    // rep(i, N) cout << B[i] << " ";
    // cout << endl;
    rep(i, N) {
        if(-B[i] % N != 0 || B[i] > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
// 1 -4 1 1 1