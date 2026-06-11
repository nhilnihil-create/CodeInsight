#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for ( int i = 0; i < N; i++ ) cin >> a.at(i);

    long long ans = 0;
    for ( int i = 1; i < N; i++ ) {
        int rest = max(0, a.at(i) + a.at(i-1) - x);
        long long sum = (long long)a.at(i-1) + a.at(i);
        /* i番目とi-1番目の隣り合う2つを考える
         * 次に一つ右隣りを見るときに有利になるように右側から減らす */
        int n = min(rest, a.at(i));
        a.at(i) -= n;
        rest -= n;
        ans += n;
        /* 右側だけではx以下を達成できない場合のみ左側も減らす */
        n = min(rest, a.at(i-1));
        a.at(i-1) -= n;
        rest -= n;
        ans += n;
    }

    cout << ans << endl;
    return 0;
}
