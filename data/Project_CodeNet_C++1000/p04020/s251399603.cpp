#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    ll ans = 0;
    rep(i, N){
        cin >> A[i];
        B[i] = A[i]%2;
        ans += A[i]/2;
    }
    rep(i, N-1){
        if(B[i] == 0){
            continue;
        } else {
            if(B[i+1] == 1){
                ans++;
                B[i+1] = 0;
            } else if(A[i+1] > 1){
                B[i+1] = 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}