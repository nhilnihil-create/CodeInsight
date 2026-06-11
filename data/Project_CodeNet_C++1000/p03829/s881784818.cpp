#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main() {
    int N,A,B;
    cin >> N >> A >> B;
    vector<int>X(N);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> X[i];
        if(i) {
            ans+=min(A*(X[i]-X[i-1]),B);
        }
    }
    cout << ans << endl;
    return 0;
}
