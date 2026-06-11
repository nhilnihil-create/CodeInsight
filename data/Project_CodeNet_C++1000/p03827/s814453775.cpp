#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 5e36+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += (S[i] == 'I')?1:-1;
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}
