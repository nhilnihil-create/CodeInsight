#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^

vector<int> D;

bool isValid(int x) {
    while(x > 0) {
        if (find(D.begin(), D.end(), x % 10) != D.end()) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;
    int tmp;
    rep(i, K) {
        cin >> tmp;
        D.push_back(tmp);
    }

    int ans;
    for (int i = N; i < 1000000; i++) { // 100000 * 5 * 10 -> OK
        if (isValid(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
