#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<bool> ok(N);
    vector<int> cnt(N,1);
    ok[0] = true;
    for(int i = 0; i < M; i++) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        if(cnt[x] == 1) {
            if(ok[x] == true) {
                ok[x] = false;
                ok[y] = true;
            }
        }
        else {
            if(ok[x] == true) {
                ok[y] = true;
            }
        }
        cnt[x]--;
        cnt[y]++;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(ok[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}
