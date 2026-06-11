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
#define int long long
int A[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N) cin >> A[i];
    int sum = 0;
    rep(i, N) sum += A[i];
    int loss = N * (N + 1) / 2;
    if (sum % loss != 0) {
        cout << "NO" << endl;
        return 0;
    }
    int cnt = sum / loss;
    int sum2 = 0;
    rep(i, N) {
        int sa = A[(i + 1) % N] - A[i] - cnt;
        //cout << sa << endl;
        if (sa > 0 || -sa % N != 0) {
            cout << "NO" << endl;
            return 0;
        }
        sum2 += -sa / N;
    }
    if (sum2 == cnt) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }




    return 0;
}
