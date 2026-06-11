#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
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
    int mx = 0;
    int GCD = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        mx = max(mx,A[i]);
        if(i == 0) {
            GCD = A[i];
        }
        else {
            GCD = gcd(GCD,A[i]);
        }
        if(A[i] == K) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    if(mx < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if((mx-K)%GCD == 0) {
        cout << "POSSIBLE" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}
