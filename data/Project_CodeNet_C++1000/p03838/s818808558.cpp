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
    ll x, y, ans;
    cin >> x >> y;

    if (x >= 0) {
        if (y >= 0) {
            if (x > y) {
                ans = 2 + x - y;
            }
            else {
                ans = y - x;
            }
        }
        else {
            if (abs(x) > abs(y)) {
                ans = 1 + x + y;
            }
            else {
                ans = 1 - x - y;
            }
        }
        if (y == 0) {
            ans--;
        }
    }
    else {
        if (y >= 0) {
            if (abs(x) > abs(y)) {
                ans = - y - x + 1;
            }
            else {
                ans = 1 + y + x;
            }
            if (y == 0) {
                ans--;
            }
        }
        else {
            if (abs(x) > abs(y)) {
                ans = y - x;
            }
            else {
                ans = 2 + x - y;
            }
        }
    }
    if (abs(x) == abs(y)) {
        ans = 1;
    }

    cout << ans << endl;
    return 0;
}