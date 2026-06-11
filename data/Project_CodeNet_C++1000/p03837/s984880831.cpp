#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[105][105];
signed main() {
    for(int i = 0; i < 105; i++) {
        for(int j = 0; j < 105; j++) {
            if(i != j) {
                cnt[i][j] = INF;
            }
        }
    }
    int N,M;
    cin >> N >> M;
    vector<int>a(M),b(M),c(M);
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;b[i]--;
        cnt[a[i]][b[i]] = min(cnt[a[i]][b[i]],c[i]);
        cnt[b[i]][a[i]] = min(cnt[b[i]][a[i]],c[i]);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                cnt[j][k] = min(cnt[j][k],cnt[i][j]+cnt[i][k]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(cnt[j][a[i]]+cnt[b[i]][k]+c[i] == cnt[j][k]) {
                    ans++;
                    goto END;
                }
            }
        }
    END:;
    }
    cout << M-ans << endl;
}
