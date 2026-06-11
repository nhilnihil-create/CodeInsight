#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, K, x, ans = 0;
    cin >> N >> K;

    rep (i, N) {
        cin >> x;
        if (x <= K){
            if ((K - x) < x){
                ans += 2 * (K - x);
            }
            else{
                ans += 2 * x;
            }
        }
        else{
            if ((x - K) < x){
                ans += 2 * (x - K);
            }
            else{
                ans += 2 * x;
            }
        }
    }
    cout << ans << endl;
}