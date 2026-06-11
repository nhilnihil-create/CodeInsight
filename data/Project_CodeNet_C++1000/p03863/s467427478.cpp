#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int nxt[maxn], lst[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        nxt[i] = i + 1, lst[i] = i - 1;
    }
    int i = 1;
    while (1) {
        if (lst[i] == -1) i = nxt[i];
        if (nxt[i] == (int)s.size()) break;
        if (s[lst[i]] != s[nxt[i]]) {
            ans++;
            nxt[lst[i]] = nxt[i];
            lst[nxt[i]] = lst[i];
            i = lst[i];
        }
        else i = nxt[i];
    }
    if (ans % 2 == 0) cout << "Second";
    else cout << "First";
    return 0;
}
