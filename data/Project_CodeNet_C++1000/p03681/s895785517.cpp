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
    if(abs(N-M) >= 2) {
        cout << 0 << endl;
    }
    else {
        int cnt = 1;
        for(int i = 1; i <= N; i++) {
            cnt*=i;
            cnt%=INF;
        }
        for(int i = 1; i <= M; i++) {
            cnt*=i;
            cnt%=INF;
        }
        if(N == M) {
            cnt*=2;
            cnt%=INF;
        }
        cout << cnt << endl;
    }
}
