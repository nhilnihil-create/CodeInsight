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
    vector<int> cnt(26, 0);

    rep(i, H) {
        rep(j, W) {
            char a;
            cin >> a;
            cnt[a - 'a']++;
        }
    }

    bool flag = true;
    if (H % 2 == 0 && W % 2 == 0) {
        rep(i, 26) {
            if (cnt[i] % 4 != 0) {
                flag = false;
                break;
            }
        }
    }
    else if (H % 2 == 1 && W % 2 == 1) {
        int one = 0, two = 0;
        rep(i, 26) {
            if (cnt[i] % 4 == 3) {
                flag = false;
                break;
            }
            else if (cnt[i] % 4 == 1) {
                one++;
            }
            else if (cnt[i] % 4 == 2) {
                two++;
            }
        }
        if (one != 1) flag = false;
        if (two > (H - 1) / 2 + (W - 1) / 2) flag = false;
    }
    else {
        if (W % 2 == 0) swap(H, W);
        int  two = 0;
        rep(i, 26) {
            if (cnt[i] % 4 == 3 || cnt[i] % 4 == 1) {
                flag = false;
                break;
            }
            else if (cnt[i] % 4 == 2) {
                two++;
            }
        }
        if (two > H / 2) flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}