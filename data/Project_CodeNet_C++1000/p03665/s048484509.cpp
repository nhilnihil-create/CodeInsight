#include <bits/stdc++.h>
using namespace std;

template <typename T>
T ipow(T b, long long e) {
    if (e == 0) {
        return 1;
    } else if (e % 2 == 0) {
        return ipow(b * b, e / 2);
    } else {
        return ipow(b * b, e / 2) * b;
    }
}

template <typename T>
T combination(int n, int r) {
    T ans = 1;
    for (int i = 0; i < r; i++) {
        ans *= n - i;
        ans /= (i + 1);
    }
    return ans;
}

int main() {
    int N, P;
    cin >> N >> P;
    int cntodd = 0, cnteven = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0)
            cnteven++;
        else
            cntodd++;
    }
    long long ans = 0;
    if (P == 0) {  // 偶数枚食べる
        // 偶数枚の袋を任意の袋数、奇数枚の袋を偶数袋
        for (int i = 0; i <= cntodd; i += 2) {
            ans += combination<long long>(cntodd, i);
        }
    } else {  // 奇数枚食べる
        // 偶数枚の袋を任意の袋数、奇数枚の袋を奇数袋
        for (int i = 1; i <= cntodd; i += 2) {
            ans += combination<long long>(cntodd, i);
        }
    }
    ans *= ipow<long long>(2, cnteven);
    cout << ans << endl;
    return 0;
}
