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
    ll N, L;
    cin >> N >> L;
    vector<ll> a(N);
    int index = -1;
    rep(i, N) {
        cin >> a[i];
    }

    rep(i, N - 1) {
        if (a[i] + a[i + 1] >= L) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        rep(i, index) {
            cout << i + 1 << endl;
        }
        for (int i = N - 1; i > index + 1; i--) {
            cout << i << endl;
        }
        cout << index + 1 << endl;
    }
    return 0;
}