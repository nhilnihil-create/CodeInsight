#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for(int i = 0; i < N-1; i++) {
        if(A[i]%2 == 0) {
            ans+=A[i]/2;
        }
        else {
            ans+=A[i]/2;
            if(A[i+1]) {
                ans++;
                A[i+1]--;
            }
        }
    }
    ans+=A[N-1]/2;
    cout << ans << endl;
}
