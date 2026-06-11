#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



int mod = 1000000007;
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
template<class... T> int add(int x, T... y) { return add(x, add(y...)); }
int mul(int x, int y) { return 1LL * x * y % mod; }
template<class... T> int mul(int x, T... y) { return mul(x, mul(y...)); }
int sub(int x, int y) { return add(x, mod - y); }
template<class V, int ME> class BIT {
public:
    V bit[1 << ME];
    V operator()(int e) { V s = 0; e++; while (e) s = add(s, bit[e - 1]), e -= e&-e; return s; }
    void update(int e, V v) { e++; while (e <= 1 << ME) bit[e - 1] = add(bit[e - 1], v), e += e&-e; }
};
//-----------------------------------------------------------------------------------
int N;
int dp[1010101];
BIT<int, 20> sm;
//-----------------------------------------------------------------------------------
int main() {
    cin >> N;

    dp[1] = N;
    sm.update(1, dp[1]);
    dp[2] = add(dp[1], mul(N - 1, N - 1), N - 1);
    sm.update(2, dp[2]);
    rep(i, 3, N + 1) {
        // Naive
        //dp[i] = add(dp[i - 1], mul(N - 1, N - 1), N - i + 2);
        //rep(j, 1, i - 2) dp[i] = add(dp[i], dp[j]);

        // Optimized
        dp[i] = add(dp[i - 1], mul(N - 1, N - 1), sm(i - 3), N - i + 2);
        sm.update(i, dp[i]);
    }

    cout << dp[N] << endl;
}