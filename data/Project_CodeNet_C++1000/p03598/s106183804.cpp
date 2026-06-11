#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, K, ans = 0;
    
    cin >> N;
    cin >> K;
    vector<int> x(N);
    rep(i, N) {
        cin >> x.at(i);
    }

    rep(i, N) {
        ans += min(x[i] ,abs(x[i] - K)) * 2;
    }

    cout << ans << endl;

    return 0;
}
