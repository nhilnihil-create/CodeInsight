#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,N) cin >> a.at(i);
    long ans = INFINITY;
    for (int bit = 0; bit < (1<<N-1); ++bit) {
        if (__builtin_popcount(bit) == K-1) {
            bool ok = true;
            long sum = 0;
            int left = a.at(0);
            for (int i = 0; i < N-1; ++i) {
                if (bit & (1<<i)) {
                    long add = max(left+1, a.at(i+1)) - left;
                    sum += left + add - a.at(i+1);
                    left += add;
                } else {
                    if (a.at(i+1) > left) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans = min(ans, sum);
        }
    }
    cout << ans << endl;
}

