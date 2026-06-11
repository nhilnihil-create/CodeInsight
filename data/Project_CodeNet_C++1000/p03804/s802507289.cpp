#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)

using ll = long long;
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    
    bool flag = false;
    rep(lux, N-M+1) {
        rep(luy, N-M+1) {
            if(A[lux][luy] == B[0][0]) {
                bool chflag = true;
                rep(dx, M) {
                    rep(dy, M) {
                        int cx = lux + dx;
                        int cy = luy + dy;
                        if(A[cx][cy] != B[dx][dy]) {
                            chflag = false;
                            break;
                        }
                    }
                    if(!chflag) break;
                }
                if(chflag) flag = true;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    
    
    string ans = ( flag ? "Yes" : "No" );
    cout << ans << "\n";
    return 0;
}
