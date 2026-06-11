#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int mod = 1000000007;

int main() {
    int N, M; cin >> N >> M;
    int sa = abs(N-M);
    if(sa > 1){
        cout << 0 << endl;
    } else {
        ll ans = 1;
        if(N == M){
            for (int i = 2; i <= N; i++){
                ans *= i;
                ans %= mod;
                ans *= i;
                ans %= mod;
            }
            ans *= 2;
            ans %= mod;
        } else {
            for (int i = 2; i <= N; i++){
                ans *= i;
                ans %= mod;
            }
            for (int i = 2; i <= M; i++){
                ans *= i;
                ans %= mod;
            }
        }

        cout << ans << endl;
    }

    return 0;
}