#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll D[3];
    rep(i,3) cin >> D[i];
    sort(D, D+3);
    ll mi = INT64_MAX;
    do {
        ll A = D[0] / 2;
        ll B = D[0] - A;
        ll diff = abs(A - B) * D[1] * D[2];
        if (mi > diff) mi = diff;
    } while(next_permutation(D, D+3));
    cout << mi << endl;
}
