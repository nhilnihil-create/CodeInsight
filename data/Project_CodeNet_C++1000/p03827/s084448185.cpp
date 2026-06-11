#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int xmax = 0;
    int x = 0;
    rep(i, N) {
        if ('I' == S.at(i)) {
            x++;
        } else {
            x--;
        }
        xmax = max(xmax, x);
    }

    cout << xmax << endl;

    return 0;
}