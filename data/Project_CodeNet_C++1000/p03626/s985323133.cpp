#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;

    long long ans;
    long long MOD = 1e9 + 7;
    int tmp;
    if (S1[0] == S2[0]) {
        ans = 3;
        tmp = 0;
    }
    else {
        ans = 6;
        tmp = 1;
    }

    if (tmp == 0) {
        for (int i = 1; i < N; i++) {
            //cout << i << endl;
            if (S1[i] == S2[i]) {
                if (tmp == 0) {
                    ans *= 2;
                    ans %= MOD;
                }
                tmp = 0;
            }
            else {
                if (tmp == 0) {
                    ans *= 2;
                    ans %= MOD;
                }
                else {
                    ans *= 3;
                    ans %= MOD;
                }
                i++;
                tmp = 1;
            }
        }
    }
    else {
        for (int i = 2; i < N; i++) {
            if (S1[i] == S2[i]) {
                if (tmp == 0) {
                    ans *= 2;
                    ans %= MOD;
                }
                tmp = 0;
            }
            else {
                if (tmp == 0) {
                    ans *= 2;
                    ans %= MOD;
                }
                else {
                    ans *= 3;
                    ans %= MOD;
                }
                i++;
                tmp = 1;
            }
        }
    }
    cout << ans << endl;
}