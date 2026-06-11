#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

#define MOD 1000000007



int main() {
    ll N; cin >> N;
    string S1, S2; cin >> S1 >> S2;
    vector<int> memo(N);
    ll ans = 3;
    int i = 1;
    if (S1[0] != S2[0]) {
        ans *= 2;
        memo[0] = memo[1] = 1;
        i++;
    }
    while (i < N) {
        if (S1[i] == S2[i]) {
            if (memo[i-1]) i++;
            else {
                ans *= 2;
                ans %= MOD;
                i++;
            }
        }
        else {
            if (memo[i-1]) ans *= 3;
            else ans *= 2;
            ans %= MOD;
            memo[i] = memo[i+1] = 1;
            i += 2;
        }
    }
    cout << ans << endl;
}
