#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
string S1, S2;
const int MOD = 1000000007;

int main() {
    cin >> N >> S1 >> S2;

    ll ans;
    int i = 0;
    bool ver = false;
    if (S1[0] == S2[0]) {
        ans = 3;
        i++;
        ver = true;
    }
    else {
        ans = 6;
        i += 2;
    }

    while (i < N) {
        if (S1[i] == S2[i]) {
            if (ver) {
                ans = (ans * 2) % MOD;
                i++;
                ver = true;
            }
            else {
                i++;
                ver = true;
            }
        }
        else {
            if (ver) {
                ans = (ans * 2) % MOD;
                i += 2;
                ver = false;
            }
            else {
                ans = (ans * 3) % MOD;
                i += 2;
                ver = false;
            }
        }
    }

    cout << ans << endl;    
    
    return 0;
}
