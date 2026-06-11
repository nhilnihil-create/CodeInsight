#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    rep(i, N + 1) {
        rep(j, M + 1) {
            if (i * (M - j) + j * (N - i) == K) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}