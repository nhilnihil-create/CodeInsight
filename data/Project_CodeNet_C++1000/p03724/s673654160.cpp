#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
int cnt[100005];
signed main() {
    int N,M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        cnt[a]++;cnt[b]++;
    }
    for(int i = 1; i <= N; i++) {
        if(cnt[i]%2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
