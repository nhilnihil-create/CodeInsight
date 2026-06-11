#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for (int i = (start); i < (int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int N, M, K;

int main(void)
{
    cin >> N >> M >> K;

    bool flag = false;
    for (int i = 0; i <= N; ++i) {
        for (int k = 0; k <= M; ++k) {
            // 横
            int ans = i * M;

            // 縦
            ans += k * (N - i);
            ans -= k * (i);

            if (ans == K) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}