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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int P = 2;
    ll ans = A[0] - 1;
    repd(i, 1, N) {
        ll cnt = A[i] / P;
        if (A[i] % P == 0) cnt--;
        if (A[i] == P) P++;
        ans += cnt;
    }

    cout << ans << endl;
    return 0;
}