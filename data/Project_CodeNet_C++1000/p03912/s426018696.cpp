#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>X(N);
    vector<int>Y(M);
    vector<int>Z(100005);
    for(int i = 0; i < N; i++) {
        cin >> X[i];
        Y[X[i]%M]++;
        Z[X[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        if(i == 0) {
            ans+=Y[i]/2;
            Y[i] = Y[i]%2;
        }
        else if(M%2 == 0 && i == M/2) {
            ans+=Y[i]/2;
            Y[i] = Y[i]%2;
        }
        else {
            ans+=min(Y[i],Y[M-i]);
            int cnt = Y[i];
            Y[i]-=min(cnt,Y[M-i]);
            Y[M-i]-=min(cnt,Y[M-i]);
        }
    }
    for(int i = 0; i <= 100000; i++) {
        if(Z[i] >= 2) {
            if(Y[i%M]) {
                ans+=min(Z[i]/2,Y[i%M]/2);
                Y[i%M]-=min(Z[i]/2*2,Y[i%M]/2*2);
            }
        }
    }
    cout << ans << endl;
}