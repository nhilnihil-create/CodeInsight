#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = INF;
    for(int bit = 0; bit < (1 << N); bit++) {
        int cnt = 0;
        int sum = 0;
        int memo = 0;
        for(int i = 0; i < N; i++) {
            if(1 & (bit >> i)) {
                cnt++;
                if(cnt != 1){
                    if(memo >= a[i]) {
                        sum+=memo+1-a[i];
                        memo = memo+1;
                    }
                }
            }
            memo = max(memo,a[i]);
        }
        if(cnt >= K) {
            ans = min(ans,sum);
        }
    }
    cout << ans << endl;
}
