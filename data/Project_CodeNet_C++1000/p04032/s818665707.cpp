#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define space ' '
typedef long long ll;
typedef long double ld;
const long double PI = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    if (n == 2 && s[0] == s[1]) {
        cout << 1 << space << 2 << endl;
        return 0;
    }
    pair<int, int> ans = { -1, -1 };
    for (int i = 0; i < n - 2; ++i) {
        unordered_map<char, int> occurs;
        occurs[s[i]] += 1;
        occurs[s[i + 1]] += 1;
        occurs[s[i + 2]] += 1;
        if (occurs[s[i]] > 1 || occurs[s[i + 1]] > 1 || occurs[s[i + 2]] > 1) {
            ans.first = i + 1;
            ans.second = i + 3;
            break;
        }
    }
    cout << ans.first << space << ans.second << endl;

    return 0;
}
