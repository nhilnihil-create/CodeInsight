#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define rep(i, n) for(int i=0;i<(n);++i)
#define INF (1ll<<60)
#define FI first
#define SE second
typedef pair<int, int> pii;
#define l_b lower_bound
#define u_b upper_bound

int N, K;
int A[100100];
int B[100100];

signed main() {
    cin >> N >> K;
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
    int maxval = 0;
    for (int r = 1; r <= K; r <<= 1) {
        if ((K & r) == 0)continue;
        int X = (K ^ r) | (r - 1);
        int val = 0;
        rep(i, N) {
            if ((A[i] | X) == X) {
                val += B[i];
            }
        }
        maxval = max(maxval, val);
    }
    int X = K;
    int val = 0;
    rep(i, N) {
        if ((A[i] | X) == X) {
            val += B[i];
        }
    }
    maxval = max(maxval, val);
    cout << maxval << endl;
}