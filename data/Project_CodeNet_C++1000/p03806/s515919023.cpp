#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int dp[41][420][420];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int inf = 1e9;
    int N,X,Y;
    cin >> N >> X >> Y;
    vec<int> A(N),B(N),C(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i] >> C[i];
    for(int i=0;i<=N;i++) for(int j=0;j<=410;j++) for(int k=0;k<=410;k++) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    for(int i=0;i<N;i++) for(int j=0;j<400;j++) for(int k=0;k<400;k++){
        int nj = j+A[i],nk = k+B[i];
        dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
        dp[i+1][nj][nk] = min(dp[i+1][nj][nk],dp[i][j][k]+C[i]);
    }
    int ans = inf;
    for(int j=0;j<410;j++) for(int k=0;k<410;k++){
        if(!j || !k) continue;
        if(j*Y==k*X) ans = min(ans,dp[N][j][k]);
    }
    cout << (ans!=inf? ans:-1) << "\n";
}