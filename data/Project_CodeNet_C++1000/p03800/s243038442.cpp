#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e7 * 2, S2 = 1e7 * 2;

char nt(char a) {
    if (a == 'S') return 'W';

    return 'S';
}
int main() {
    fastInp;

    ll n;
    string s;
    cin >> n;
    cin >> s;

    string ans;
    for (int i = 0; i < 4; i++) {
        ans.clear();
        if (i % 2 == 0) {
            ans.push_back('S');
        }
        else {
            ans.push_back('W');
        }
        if (i / 2 == 0) {
            ans.push_back('S');
        }
        else {
            ans.push_back('W');
        }
        ans.resize(n);
        for (int i = 1; i < n - 1; i++) {
            if (ans[i] == 'S') {
                if (s[i] == 'o') {
                    ans[i + 1] = ans[i - 1];
                }
                else {
                    ans[i + 1] = nt(ans[i - 1]);
                }
            }
            if (ans[i] == 'W') {
                if (s[i] == 'o') {
                    ans[i + 1] = nt(ans[i - 1]);
                }
                else {
                    ans[i + 1] = (ans[i - 1]);
                }
            }
        }

        bool flag = true;
        if (ans[n - 1] == 'S') {
            if (ans[0] != ans[n - 2] && s[n - 1] == 'o') flag = false;
            if (ans[0] == ans[n - 2] && s[n - 1] == 'x') flag = false;
        }
        if (ans[n - 1] == 'W') {
            if (ans[0] != ans[n - 2] && s[n - 1] == 'x') flag = false;
            if (ans[0] == ans[n - 2] && s[n - 1] == 'o') flag = false;
        }
        bool flag2 = true;
        if (ans[0] == 'S') {
            if (ans[n - 1] != ans[1] && s[0] == 'o') flag2 = false;
            if (ans[n - 1] == ans[1] && s[0] == 'x') flag2 = false;
        }

        if (ans[0] == 'W') {
            if (ans[n - 1] != ans[1] && s[0] == 'x') flag2 = false;
            if (ans[n - 1] == ans[1] && s[0] == 'o') flag2 = false;
        }
        if (flag2 && flag) {
            cout << ans;
            return 0;
        }
    }

    cout << "-1";
    return 0;
}

