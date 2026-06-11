#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {

    string s; cin >> s;
    int ans;
    for ( int i = 2; i <= s.size() - 2; i += 2) {
        string left = s.substr(0, (s.size() - i) / 2);
        string right = s.substr((s.size() - i) / 2, (s.size() - i) / 2);
        if (left == right) {
            ans = 2 * left.size();
            break;
        }
    }

    cout << ans << endl;
    return 0;
}