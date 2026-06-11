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
    int N, x;
    cin >> N >> x;
    vector<int> ans(2 * N - 1, 0);
    bool flag = false;

    if (x >= 2 && x <= 2 * N - 2) {
        cout << "Yes" << endl;
        ans[N - 1] = x;
        if (x != 2 * N - 2) {
            ans[N] = x - 1;
            ans[N - 2] = x + 1;
            ans[N + 1] = x + 2;
            int num = 1;
            rep(i, 2 * N - 1) {
                if (ans[i] != 0) continue;
                if (num == x - 1) num += 4;
                ans[i] = num;
                num++;
            }
        }
        else {
            ans[N] = x + 1;
            ans[N - 2] = x - 1;
            ans[N + 1] = x - 2;
            int num = 1;
            rep(i, 2 * N - 1) {
                if (ans[i] != 0) continue;
                if (num == x - 2) num += 4;
                ans[i] = num;
                num++;
            }
        }
        rep(i, 2 * N - 1) cout << ans[i] << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}