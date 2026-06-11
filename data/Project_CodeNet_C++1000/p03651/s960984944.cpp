#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int gcd(int X,int Y) {
    if(X%Y == 0) {
        return Y;
    }
    else {
        return gcd(Y,X%Y);
    }
}
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>A(N);
    int gd = 0,mx = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        mx = max(mx,A[i]);
        if(i) gd = gcd(gd,A[i]);
        else gd = A[i];
    }
    if(mx >= K && (K-mx)%gd == 0) {
        cout << "POSSIBLE" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}
