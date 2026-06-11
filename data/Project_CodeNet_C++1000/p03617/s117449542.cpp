#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ll Q, H, S, D, N;
    ll m;
    ll ans = 0;
    ll count;

    cin >> Q >> H >> S >> D;
    cin >> N;

    m = min({8*Q, 4*H, 2*S, D});
    count = N / 2;
    ans += count * m;
    N -= (N/2) * 2;

    m = min({4*Q, 2*H, S});
    count = N / 1;
    ans += count * m;
    N -= (N/1);

    m = min({2*Q, H});
    count = N / 0.5;
    ans += count * m;
    N -= (N/0.5);

    m = Q;
    count = N / 0.25;
    ans += count * m;
    N -= (N/0.25);


    cout << ans << endl;
}
