#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    int ans = 0;
    int X = 0;
    int Y = 0;
    for(int i = 0; i < N; i++) {
        int T,A;
        cin >> T >> A;
        if(i == 0) {
            ans = T+A;
            X = T;
            Y = A;
        }
        else {
            if(X >= T || Y >= A) {
                ans+=max((X+T-1)/T,(Y+A-1)/A)*(T+A)-ans;
                X = max((X+T-1)/T,(Y+A-1)/A)*T;
                Y = max((X+T-1)/T,(Y+A-1)/A)*A;
            }
            else {
                ans = T+A;
                X = T;
                Y = A;
            }
        }
    }
    cout << ans << endl;
}