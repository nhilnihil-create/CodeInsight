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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
    }

    ll cnt = 0;
    for (ll i = N - 1; i >= 0; i--) {
        A[i] += cnt;
        if (A[i] % B[i]) cnt += B[i] - (A[i] % B[i]);
    }

    cout << cnt << endl;
    return 0;
}