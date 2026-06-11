#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n, k;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> k;
    n = s.size();
    for (int i = 0; i < n; i++) {
        int val = ('z' - s[i] + 1) % 26;
        if (k >= val) {
            s[i] = 'a';
            k -= val;
        }
    }
    s[n - 1] += k % 26;
    if (s[n - 1] > 'z') s[n - 1] -= 26;
    cout << s;
    return 0;
}
