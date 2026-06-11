#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, M, a, b;
    cin >> N >> M;
    vector<int> ans(N, 0);
    rep(i, M){
        cin >> a >> b;
        ans[a - 1] += 1;
        ans[b - 1] += 1;
    }
    rep(i, N){
        cout << ans[i] << endl;
    }
}
