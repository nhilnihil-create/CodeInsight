#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    ll P = 1, ans = 0;
    rep(i, N) {
        if (A[i] < P) {
            continue;
        }
        if (A[i] == P) {
            P++;
            continue;
        }
        ans += (A[i] - 1) / P;
        if (P == 1) P++;
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;
}