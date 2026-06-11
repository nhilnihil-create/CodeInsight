#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>A(N,vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<bool>ok(M,true);
    int ans = INF;
    int X = M;
    while(X--) {
        vector<P>cnt = {{0,0}};
        map<int,int>Mp;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(ok[A[i][j]]) {
                    Mp[A[i][j]]++;
                    goto home;//gotoキャンペーン！！
                }
            }
        home:;
        }
        for(P x:Mp) {
            cnt.push_back({x.second,x.first});
        }
        sort(cnt.rbegin(),cnt.rend());
        ans = min(ans,cnt[0].first);
        ok[cnt[0].second] = false;
    }
    cout << ans << endl;
}
