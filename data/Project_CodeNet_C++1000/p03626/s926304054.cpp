#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
int main()
{
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;

    int kind = 0;
    ll ans = 1;
    rep(i, N) {
        if (S1[i] == S2[i]) {
            if (kind == 0) {
                ans *= 3;
            }
            else if (kind == 1) {
                ans *= 2;
            }
            else if (kind == 2) {
                ans *= 1;
            }
            kind = 1;
        }
        else {
            i++;
            if (kind == 0) {
                ans *= 6;
            }
            else if (kind == 1) {
                ans *= 2;
            }
            else if (kind == 2) {
                ans *= 3;
            }
            kind = 2;
        }
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}