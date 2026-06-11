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
    string A;
    cin >> A;

    ll len = (ll)A.size();
    ll ans = (len * (len - 1)) / 2;

    vector<ll> alpha(26, 0);
    rep(i, A.size()) {
        alpha[A[i] - 'a']++;
    }

    rep(i, 26) ans -= (alpha[i] * (alpha[i] - 1)) / 2;

    cout << ans + 1 << endl;
    return 0;
}