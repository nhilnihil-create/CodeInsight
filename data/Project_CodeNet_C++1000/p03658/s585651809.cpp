#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> bars(N);
    rep(i, N){
        cin >> bars.at(i);
    }

    sort(bars.begin(), bars.end(), greater<int>());
    int ans = 0;
    rep(i, K){
        ans += bars.at(i);
    }
    cout << ans << endl;
}