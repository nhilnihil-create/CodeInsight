#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    
    long long q = Q * 8;
    long long h = H * 4;
    long long s = S * 2;
    long long d = D;
    long long a = min({q, h, s, d});
    long long ans = N / 2 * a;
    if (N & 1) {
        long long b = min({q, h, s}) / 2;
        ans += b;
    }
    cout << ans << endl;
    return 0;
}
