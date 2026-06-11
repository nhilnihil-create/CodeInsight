#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int INF = 1000000007;

    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    ll ans = 1;
    // 一つ左が縦ならtrue, 横ならfalse
    bool flag;
    for (int i = 0; i < N; i++) {
        //縦かどうか
        if (S1[i] == S2[i]) {
            if (i == 0)
                ans *= 3;
            else if (flag)
                ans = ans % INF * 2;
            else if (!flag)
                ans = ans % INF * 1;
            flag = true;
        } else {
            if (i == 0)
                ans *= 6;
            else if (flag)
                ans = ans % INF * 2;
            else if (!flag)
                ans = ans % INF * 3;
            i++;
            flag = false;
        }
    }
    cout << ans % INF << endl;
}