#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

int main() {

    int N, x;
    cin >> N >> x;

    if (x == 1 || x == 2 * N - 1) cout << "No" << endl;
    else if (N == 2) {
        cout << "Yes" << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
    } else {
        cout << "Yes" << endl;
        vector<bool> used(2 * N, false);
        vector<int> ans(2 * N, 0);
        ans[N] = x; used[x] = true;
        if (x > 2) {
            ans[N + 1] = x + 1; used[x + 1] = true;
            ans[N - 1] = x - 1; used[x - 1] = true;
            ans[N + 2] = x - 2; used[x - 2] = true;
        } else {
            ans[N + 1] = x - 1; used[x - 1] = true;
            ans[N - 1] = x + 1; used[x + 1] = true;
            ans[N + 2] = x + 2; used[x + 2] = true;
        }
        int now = 1;
        for (int i = 1; i <= 2 * N - 1; i++) {
            if (ans[i] > 0) continue;
            while (used[now]) now++;
            ans[i] = now; used[now] = true;
        }
        for (int i = 1; i <= 2 * N - 1; i++) {
            cout << ans[i] << endl;
        }
    }
    
    return 0;
}