#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N, M; cin >> N >> M;
    vector<int> cnt(N);
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        cnt[a] += 1;
        cnt[b] += 1;
    }
    rep(i, N) {
        if (cnt[i] % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}