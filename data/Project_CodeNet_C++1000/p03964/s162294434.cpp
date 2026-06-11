#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<ll, ll> P;
int main()
{
    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    rep(i, N) cin >> T[i] >> A[i];

    ll t = T[0], a = A[0];
    repd(i, 1, N) {
        ll tt = 1, aa = 1;
        if (t > T[i]) {
            tt = (t + T[i] - 1) / T[i];
        }
        if (a > A[i]) {
            aa = (a + A[i] - 1) / A[i];
        }
        t = T[i] * max(tt, aa);
        a = A[i] * max(tt, aa);
    }

    cout << t + a << endl;
    return 0;
}