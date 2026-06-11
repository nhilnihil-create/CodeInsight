#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    string B[2];
    rep(i,2) {
        cin >> B[i];
    }

    ll way = 0;
    ll MOD = (ll)pow(10,9) + 7;
    bool isPrevX = false;
    rep(i,N) {
        char a = B[0][i];
        if (a == B[1][i]) {
            // X
            if (i == 0) {
                way = 3;
            } else {
                if (isPrevX) {
                    way = way * 2 % MOD;
                } // else way *= 1 % mod;
            }
            isPrevX = true;
        } else if (a == B[0][i+1]) {
            // Y
            if (i == 0) {
                way = 6;
            } else if (isPrevX) {
                way = way * 2 % MOD;
            } else {
                way = way * 3 % MOD;
            }
            isPrevX = false;
            i++;
        }
    }
    cout << way << endl;
}
