#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    int ans = 0;
    for(int i = N-1; i >= 0; i--) {
        if((ans+A[i])%B[i]) {
            ans+=B[i]-(A[i]+ans)%B[i];
        }
    }
    cout << ans << endl;
}