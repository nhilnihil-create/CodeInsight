#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N, 0);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        ++cnt[a - 1];
        ++cnt[b - 1];
    }
    bool judge = true;
    rep(i, N) {
        if (cnt[i] % 2) judge = false;
    }
    cout << (judge ? "YES\n" : "NO\n");
    return 0;
}
