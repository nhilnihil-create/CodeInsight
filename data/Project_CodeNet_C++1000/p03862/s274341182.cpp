#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, x; cin >> N >> x;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 1; i < N; i++){
        int now = A[i-1] + A[i];
        if(now > x){
            int d = now - x;
            ans += d;
            if(d <= A[i]){
                A[i] -= d;
            } else {
                A[i-1] -= d-A[i];
                A[i] = 0;
            }
        }    
    }

    cout << ans << endl;

    return 0;
}