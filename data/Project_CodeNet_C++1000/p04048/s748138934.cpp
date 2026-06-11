#include <bits/stdc++.h>
using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;

const long long INF = 1LL << 60;

ll reflect(ll a, ll b) {
    if (a > b) swap(a, b);
    if (b % a == 0) {
        return (2 * (b / a) - 1) * a;
    }
    else {
        return 2 * (b / a) * a + reflect(a, b % a);
    }
}

int main()
{
    ll N, X;
    cin >> N >> X;

    cout << N + reflect(N - X, X) << endl;

    return 0;
}