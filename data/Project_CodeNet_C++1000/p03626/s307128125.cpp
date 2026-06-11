#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main() {
    ll N;
    string s1, s2;
    ll i = 0;
    ll ans = 1;
    bool state;
    cin >> N;
    cin >> s1;
    cin >> s2;

    if (s1[i]== s2[i]) {
        state = true;
        ans *= 3;
        i++;
    } else {
        state = false;
        ans *= 6;
        i += 2;
    }
    while (i < N) {
        if (s1[i] == s2[i]) {
            if (state) {
                ans *= 2;
            } else {
                state = true;
            }
            i++;
        } else {
            if (state) {
                ans *= 2;
                state = false;
            } else {
                ans *= 3;
            }
            i += 2; 
        }
    }

    cout << ans % MOD << endl;
}
