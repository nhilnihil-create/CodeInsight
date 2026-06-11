#include <bits/stdc++.h>

using namespace std;

// 平行四辺形状の領域に入ってからの移動距離
long long f(long long yoko, long long tate) {
    long long y = yoko, t = tate;
    if (y < t) swap(y, t);
    if (y % t == 0) { // このときはゴールできる
        return 2LL * y - t;
    } else {
        return f(y % t, t - y % t) + 2LL * y;
    }
}

int main() {
    long long n, x;
    cin >> n >> x;

    cout << n + f(x, n - x) << endl;
    return 0;
}