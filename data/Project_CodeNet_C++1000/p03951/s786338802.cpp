#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    string ns, nt;
    rep(i, s.size()) {
        ns = s.substr(i);
        nt = t.substr(0, s.size() - i);
        if (ns == nt)
            break;
    }

    int res;
    if (ns != nt)
        res = N * 2;
    else
        res = N * 2 - ns.size();
    cout << res << endl;
}