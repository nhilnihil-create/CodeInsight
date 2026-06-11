#include <bits/stdc++.h>
#define int long long
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int N, A, B;
vector <int> h;

template <class T>
bool c(T mid) {
    vector <int> tmp = h;
    rep (i, N) h[i] -= B * mid;

    for (int i = 0; i < N; i++) {
        if (h[i] > 0) mid -= h[i] / (A - B) + (h[i] % (A - B) != 0);
    }

    h = tmp;
    return mid < 0;
}

template <class T>
T execute(T low, T high) {
    for(int i = 0; i < 100; i++) {
        T mid = (high + low) / 2;
        (c(mid) ? low : high) = mid;
    }
    return high;
}

signed main() {
    cin >> N >> A >> B;
    h = vector <int> (N);
    rep (i, N) cin >> h[i];

    cout << execute(0LL, 1000000000LL) << endl;

    return 0;
}