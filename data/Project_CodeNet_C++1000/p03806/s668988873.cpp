#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
#define PI  acos(-1)
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
typedef long double ld;
int main() {
    int n, ma, mb; cin >> n >> ma >> mb;
    int A[41], B[41], C[41], dp[41][411][411];
    rep(i, n) cin >> A[i] >> B[i] >> C[i];
    Fill(dp, 1 << 27);dp[0][0][0]=0;
    rep(i, n) {
        rep(ca, 411) {
            rep(cb, 411) {
                if (dp[i][ca][cb] == 1 << 27) continue;
                dp[i + 1][ca][cb] = min(dp[i + 1][ca][cb], dp[i][ca][cb]);
                dp[i + 1][ca + A[i]][cb + B[i]] = min(dp[i + 1][ca + A[i]][cb + B[i]], dp[i][ca][cb] + C[i]);
            }
        }
    }int ans = 1 << 28;
    req(ca, 410) {
        req(cb, 410) {
            if (ca * mb == cb * ma) ans = min(ans, dp[n][ca][cb]);
        }
    }
    if(ans == 1 << 27) ans = -1;
    cout << ans << endl;
}