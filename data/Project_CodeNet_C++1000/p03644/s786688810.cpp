#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    int ans = 1;
    while (ans*2 <= N) ans *= 2;
    cout << ans << endl;

    return 0;
}