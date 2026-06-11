#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    int A[100010];
    rep(i, N) cin >> A[i];

    int ans = 1;

    bool up = false;
    bool down = false;

    for (int i = 1; i < N; ++i)
    {
        int dif = A[i] - A[i-1];
        if (dif > 0) up = true;
        if (dif < 0) down = true;
        if (up && down) {
            ans++;
            up = down = false;
            continue;
        }
    }

    cout << ans << endl;

    return 0;
}