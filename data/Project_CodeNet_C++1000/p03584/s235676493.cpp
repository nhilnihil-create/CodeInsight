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
int N, K;
int A[100010], B[100010];
int ans = 0;
int calc(int K, int bit, int s) {
    //cout << K << " " << bit << " " << s << " ";
    if (bit < 0) {
        int sum = 0;
        rep(i, N) {
            if (A[i] == 0) sum += B[i];
        }
        return sum + s;
    }
    int sum = 0;
    int k = K - (K & (1 << bit));
    if (K & (1 << bit)) {
        rep(i, N) {
            if (!(A[i] & (1 << bit)) && A[i] <= K) sum += B[i];
            A[i] = A[i] - (A[i] & (1 << bit));
        }
    }
    //cout << sum << endl;
    return max(sum, calc(k, bit - 1, s));
    
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> K;
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
    cout << calc(K, 31, 0) << endl;

    return 0;
}
