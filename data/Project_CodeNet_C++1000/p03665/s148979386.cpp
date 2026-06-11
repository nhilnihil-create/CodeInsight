#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N, P;
    cin >> N >> P;
    vector<ll> ans0(N);
    vector<ll> ans1(N);
    rep(i, N) {
        int A;
        cin >> A;
        if (i == 0) {
            if (A%2 == 0) {
                ans0[0] = 2;
                ans1[0] = 0;
            }
            else {
                ans0[0] = 1;
                ans1[0] = 1;
            }
            continue;
        }
        if (A%2 == 0) {
            ans0[i] = ans0[i-1] *= 2;
            ans1[i] = ans1[i-1] *= 2;
        }
        else if (A%2 == 1) {
            ans0[i] = ans1[i-1] + ans0[i-1];
            ans1[i] = ans1[i-1] + ans0[i-1];    
        }
    }
    if (P == 1) {
        cout << ans1[N-1] << endl;
    }
    else {
        cout << ans0[N-1] << endl;
    }
}