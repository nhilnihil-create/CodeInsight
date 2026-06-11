#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    rep(i, N) {
        ll X = i, Y = N - 1 - i;
        if (A + C * X - D * Y <= B && B <= A + D * X - C * Y) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}