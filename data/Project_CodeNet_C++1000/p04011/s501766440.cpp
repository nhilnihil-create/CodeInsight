#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    int ans;
    if(N > K) ans = K* X + (N - K)*Y;
    else ans = N * X;
    cout << ans << endl;
}
