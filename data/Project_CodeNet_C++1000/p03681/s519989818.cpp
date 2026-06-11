#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // 2以上差がある場合は必ず隣り合ってしまうので0になる
    // 1差がある場合は、先頭に来るのが猿か犬か多い方に必ず決まる。
    // なので、犬の並べ方の組み合わせ N! * 猿の並べ方の組み合わせ M!になる
    // 同数の場合は その組み合わせに加えてどちらが先頭に来るかが考えに加わるので 2 * N! * M! になる
    int N, M;
    cin >> N >> M;
    int sa = abs(N - M);
    if (sa >= 2) {
        cout << 0 << endl;
        return 0;
    }

    bool dousuu = M == N;
    int64_t ans = 1;
    while (N > 0) {
        ans = ans * N % int(pow(10, 9.0) + 7);
        N = N - 1;
    }

    while (M > 0) {
        ans = ans * M % int(pow(10, 9.0) + 7);
        M = M - 1;
    }

    if (dousuu) {
        ans = ans * 2 % int(pow(10, 9.0) + 7);
    }

    cout << ans << endl;
    return 0;
}
