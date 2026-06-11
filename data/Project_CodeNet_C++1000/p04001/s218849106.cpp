#include <iostream>
#include <string>
using namespace std;
using llong = long long;

llong ans;

llong c2ll(int i, const string &s) { return s[i] - '0'; }

void func(int i, llong tmp, llong sum, const string &s) {
    if (i + 1 == s.length()) {
        ans += tmp + sum;
        return;
    }

    llong tmp1 = tmp * 10 + c2ll(i + 1, s);
    func(i + 1, tmp1, sum, s);

    sum += tmp;
    tmp = c2ll(i + 1, s);
    func(i + 1, tmp, sum, s);
}

int main() {
    string s;
    cin >> s;

    func(0, c2ll(0, s), 0LL, s);
    cout << ans << endl;
    return 0;
}
