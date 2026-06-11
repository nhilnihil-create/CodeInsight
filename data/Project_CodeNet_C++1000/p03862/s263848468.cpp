#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    repd(i, 1, N) {
        int candy = A[i] + A[i - 1];
        ans += max(0, candy - X);
        A[i] -= min(A[i], max(0, candy - X));
    }

    cout << ans << endl;
    return 0;
}