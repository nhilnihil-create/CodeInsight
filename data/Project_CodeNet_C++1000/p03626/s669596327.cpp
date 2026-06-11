#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





int main() {
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    ll mod = 1000000007;
    ll d;
    int idx = 0;
    if (S1[0] == S1[1]) {
        d = 6;
        idx = 2;
    } else {
        d = 3;
        idx = 1;
    }
    while (idx < N) {
        if (idx + 1 < N && S1[idx] == S1[idx + 1]) {
            if (S1[idx - 1] == S2[idx - 1]) {
                d *= 2;
            } else {
                d *= 3;
            }
            idx += 2;
        } else if (S1[idx - 1] == S2[idx - 1]){
            d *= 2;
            idx++;
        } else {
            idx++;
        }
        d %= mod;
    }
    cout << d << "\n";
    return 0;
}