#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    int sum=0;
    rep(i,n) {
        cin >> s.at(i);
        sum += s.at(i);
    }

    sort(s.begin(), s.end());
    if (sum%10) {
        cout << sum << endl;
        return 0;
    }

    rep(i,n) {
        if (s.at(i)%10) {
            cout << sum-s.at(i) << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
