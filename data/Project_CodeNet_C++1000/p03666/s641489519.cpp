#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    ll G = abs(A - B);
    int x = (G + D - 1) / D;
    if (x > N - 1) {
        cout << "NO\n";
        return 0;
    }
    if ((x + N) % 2 == 0) x++;
    //cout << "x=" << x << "\n";
    if (x * C <= G) {
        cout << "YES\n";
        return 0;
    }
    if ((x - 1) * C - D <= G && G <= (x - 1) * D - C) {
        cout << "YES\n";
        return 0;
    }
    ll d = min({abs(G - x * C), abs((x - 1) * D - C - G), abs((x - 1) * C - D - G)});
    if ((D - C) * (N - 1 - x) / 2 >= d) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}