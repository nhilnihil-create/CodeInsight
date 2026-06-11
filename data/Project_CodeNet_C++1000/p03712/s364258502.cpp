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
    int H, W;
    cin >> H >> W;

    vector<string> a(H);
    rep(i, H) cin >> a[i];

    rep(i, H + 2) {
        rep(j, W + 2) {
            if (i == 0 || i == H + 1) {
                cout << '#';
            }
            else if (j == 0 || j == W + 1) {
                cout << '#';
            }
            else {
                cout << a[i - 1][j - 1];
            }
        }
        cout << endl;
    }
    return 0;
}