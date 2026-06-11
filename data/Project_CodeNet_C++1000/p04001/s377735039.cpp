#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


string s;
ll sum = 0;  

void calc(int ind, ll now1, ll now2) {
    if (ind == s.size()) {
        sum += now1 + now2;
        return;
    }

    calc(ind + 1, s[ind] - '0', now1 + now2);
    calc(ind + 1, now1 * 10 + (s[ind] - '0'), now2);
}

int main() {
    cin >> s;
    calc(0, 0, 0);

    cout << sum / 2ll << endl;
    return 0;
}