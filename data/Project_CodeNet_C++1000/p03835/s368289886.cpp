#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int K, S;


void input() {
    cin >> K >> S;
}


int main() {
    input();
    int ans = 0;
    rep(x, K + 1) rep(y, K + 1) {
        int z = S - (x + y);
        if (0 <= z && z <= K) ans++;
    }
    cout << ans << endl;
}
