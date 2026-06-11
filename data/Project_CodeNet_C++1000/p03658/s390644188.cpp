#include<iostream>
#include<algorithm>
#include<math.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N; cin >> N;
    int K; cin >> K;
    int l[110]; rep(i, N) cin >> l[i];

    sort(l, l+N, greater<int>());

    int res = 0;
    rep(i, K) res += l[i];

    cout << res << endl;
    return 0;
}
