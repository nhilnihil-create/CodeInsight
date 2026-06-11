#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for (char c : s) {
        int pcnt = 0;
        int cnt = 0;
        int tmp = 0;
        for (int i = 0; i < n;) {
            if (s[i] == c) {
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] != c) j++;
            tmp = max(tmp, j - i);
            i = j;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
