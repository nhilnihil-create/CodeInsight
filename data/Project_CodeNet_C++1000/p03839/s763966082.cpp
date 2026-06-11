#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>
#include<bitset>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N, K;
int A[100100];
int psum[100100];//positive sum
int ksum[100100];//ksum[i]:=a[i]+a[i-1]+...+a[i-K+1];
signed main() {
    cin >> N >> K;
    int ks = 0;
    rep(i, N) {
        cin >> A[i];
        if (A[i] > 0)psum[i + 1] = psum[i] + A[i];
        else psum[i + 1] = psum[i];
        ks += A[i];
        if (i - K + 1 > 0)ks -= A[i - K];
        ksum[i] = max(ks, 0ll);
    }
    int ans = 0;
    for (int i = K - 1; i < N; ++i) {
        ans = max(ans, ksum[i] + psum[i - K + 1] + psum[N] - psum[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
