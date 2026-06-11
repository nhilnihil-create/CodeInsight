#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)

int main() {
    int n; cin >> n;
    vector<int> s(n);
    int sum = 0;
    rep(i, n) {
        cin >> s[i];
        sum += s[i];
    }
    if (sum%10) {
        cout << sum << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    rep(i, n) {
        if (s[i]%10) {
            sum -= s[i];
            break;
        }
    }
    if (sum%10) {
        cout << sum << endl;
    } else {
        cout << 0 << endl;
    }
}