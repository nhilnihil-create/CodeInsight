#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string s;
    cin >> s;
    stack<char> STs;
    rep(i, s.size()) {
        if (s[i] == 'T') {
            if (STs.empty() || STs.top() != 'S')
                STs.push(s[i]);
            else
                STs.pop();
        } else
            STs.push(s[i]);
    }

    int res = STs.size();
    cout << res << endl;
}