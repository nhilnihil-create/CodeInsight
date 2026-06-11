#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        sum+=A[i];
        if(i+1 != N) {
            if(sum*2 >= A[i+1]) {
                ans++;
            }
            else {
                ans = 0;
                
            }
        }
    }
    ans++;
    cout << ans << endl;
}
