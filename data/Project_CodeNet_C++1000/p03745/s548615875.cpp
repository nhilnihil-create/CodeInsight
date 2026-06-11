#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int A[N];
    rep(i, N) cin >> A[i];

    bool inc = false, dec = false;
    int ans = 1;

    rep(i, N-1) {
        if (A[i+1] > A[i]) inc = true;
        else if (A[i+1] < A[i]) dec = true;

        if (inc && dec) {
            ans++;
            inc = false;
            dec = false;
        }
    }

    cout << ans << endl;

   return 0;
}