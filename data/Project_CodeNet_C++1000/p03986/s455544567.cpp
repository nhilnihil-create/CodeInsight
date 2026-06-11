#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n, cnt, sol;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else if (cnt > 0) {
            cnt--;
            sol++;
        }
    }
    cout << n - 2 * sol;
    return 0;
}
