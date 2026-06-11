#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e8;
const int INF = 1e9;
const int MOD = 998244353;



int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool av = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (s[i] == 'p' ? 0 : 1);
        if (!av)
            ans--;
        av = 1 - av;
    }
    cout << ans;
}