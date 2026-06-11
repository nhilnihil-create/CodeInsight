#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M,R;
    cin >> N >> M >> R;
    vector<int>r(R);
    for(int i = 0; i < R; i++) {
        cin >> r[i];
        r[i]--;
    }
    sort(r.begin(),r.end());
    vector<vector<int>>cnt(N,vector<int>(N,INF));
    for(int i = 0; i < M; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        A--;B--;
        cnt[A][B] = C;
        cnt[B][A] = C;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                cnt[j][k] = min(cnt[j][k],cnt[i][j]+cnt[i][k]);
            }
        }
    }
    int ans = INF;
    do {
        int sum = 0;
        for(int i = 0; i < R-1; i++) {
            sum+=cnt[r[i]][r[i+1]];
        }
        ans = min(ans,sum);
    }while(next_permutation(r.begin(),r.end()));
    cout << ans << endl;
}
