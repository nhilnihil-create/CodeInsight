#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

//#define DEBUG

#ifdef DEBUG
constexpr int K = 5;
#else
constexpr int K = 9;
#endif

template <class F>
int lower_bound(int i0, int i1, F f) {
    while (i0 < i1) {
        int i = (i0 + i1) / 2;
        if (f(i)) i1 = i; else i0 = i + 1;
    }
    return i0;
}

constexpr int64_t pow10(int k) {
    int64_t r = 1;
    for (int i = 0; i < k; i++) r *= 10;
    return r;
}

bool query(int64_t n) {
    if (n > pow10(K * 2)) throw;
    cout << "? " << n << endl;
#ifdef DEBUG
    constexpr int64_t N = 1234;
    return !((n <= N) ^ (to_string(n) <= to_string(N)));
#else
    char a;
    cin >> a;
    return a == 'Y';
#endif
}

int main() {
    int64_t r = 0, t = 10;

    for (int j = 0; j < K; j++) {
        r *= 10;
        int i = lower_bound(1, 10, [&](int i) {
            // n>Nなのでstr(n)>str(N)が返る ただしj==0&&i==0&&N==10^Kのときは両方逆になって上手くいく
            return query((r + i) * pow10(K)); // iが大きくなるほど満たされやすくなる条件
        });
        if (j == 0 && i == 1) {
            // 辞書順で10^Kのほうが大きいということは、10冪だった
            t = 3;
            r = 0;
            break;
        }
        r += i - 1; // 求めやすいようにupper_bound
    }
    // lower_boundに直す
    r += 1;

    while (r % 10 == 0) r /= 10;
    while (t <= r) t *= 10;

    for (int i = 0; i < K; i++) {
        // 10冪のとき、str(n)>str(N)なのでn>Nが返る
        // ちがうとき、str(n)<str(N)なのでn<=Nが返る
        if ((t % 3 != 0) ^ query(t)) break;

        t *= 10;
        r *= 10;
    }

    cout << "! " << r << endl;

    return 0;
}