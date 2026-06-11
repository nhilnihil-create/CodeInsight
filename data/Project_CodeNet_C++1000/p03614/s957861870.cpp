#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>p(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(i+1 == p[i]) {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
}
