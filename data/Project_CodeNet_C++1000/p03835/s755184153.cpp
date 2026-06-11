#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int K,S;
    cin >> K >> S;
    int ans = 0;
    for(int i = 0; i <= K; i++) {
        for(int j = 0; i+j <= S && j <= K; j++) {
            if(S-i-j <= K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
