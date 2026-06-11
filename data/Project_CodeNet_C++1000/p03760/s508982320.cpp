#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
 
int main()
{
    string o, e;
    cin >> o;
    cin >> e;
    string ans;
    rep(i, e.size()) {
        ans.push_back(o[i]);
        ans.push_back(e[i]);
    }
    if(o.size() != e.size()) {
        ans.push_back(o[o.size() - 1]);
    }
    cout << ans << endl;
    return 0;
}