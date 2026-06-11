#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'a') continue;
        int dist = 'z' - s[i] + 1;
        if (dist <= k) {
            s[i] = 'a';
            k -= dist;
        }
    }
    ll c = s[n - 1] + k % 26;
    if (c > (int)'z') s[n - 1] = (char)(c - 26);
    else s[n - 1] = (char)c;
    cout << s << endl;
}
