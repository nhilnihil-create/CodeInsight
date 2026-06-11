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
    vector<int>a(3*N);
    for(int i = 0; i < 3*N; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 3*N-2; i >= N; i-=2) {
        ans+=a[i];
    }
    cout << ans << endl;
}
