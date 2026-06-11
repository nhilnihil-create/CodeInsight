#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, K, X, Y;
    cin >> N >> K >> X >> Y;
    if (N <= K) cout << N * X << endl;
    else cout << K * X + (N - K) * Y << endl;
}

