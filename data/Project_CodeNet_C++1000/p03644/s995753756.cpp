#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int macnt = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        int s = i;
        while (s % 2 == 0) {
            cnt++;
            s /= 2;
        }

        if (cnt >= macnt)
            macnt = cnt, ans = i;
    }

    cout << ans << endl;

    return 0;
}