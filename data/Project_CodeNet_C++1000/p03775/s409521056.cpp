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

int keta(ll n) {
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}
int main()
{
    ll N;
    cin >> N;

    int ans = 1e9;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i) continue;
        chmin(ans, max(keta(i), keta(N / i)));
    }

    cout << ans << endl;
    return 0;
}