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
    ll ans = 0, sum = 0;
    rep(i, N) {
        int A;
        cin >> A;
        if (A != 0) {
            sum += A;
        }
        else {
            ans += sum / 2;
            sum = 0;
        }
    }

    cout << ans + sum / 2 << endl;
    return 0;
}