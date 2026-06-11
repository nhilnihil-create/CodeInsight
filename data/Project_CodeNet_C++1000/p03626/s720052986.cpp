#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

int main(void) {
    int N;
    cin >> N;
    vector<string> S(2);
    cin >> S[0];
    cin >> S[1];

    int64_t ans = 3;
    if(S[0][0] != S[1][0]) {
        ans *= 2;
    }
    for(int i=1; i<N; i++) {
        if(S[0][i] == S[1][i]) {
            if(S[0][i-1] == S[1][i-1]) {
                ans = (ans * 2) % MOD;
            }
        } else if(S[0][i-1] == S[1][i-1]) {
            ans = (ans*2) % MOD;
        } else if(S[0][i-1] != S[0][i]) {
            ans = (ans * 3) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
