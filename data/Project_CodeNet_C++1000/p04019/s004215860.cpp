#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    string ss; cin >> ss;
    bool n = 0, s = 0, e = 0, w = 0;
    rep(i, 0, ss.size()) {
        if (ss[i] == 'W') w = 1;
        if (ss[i] == 'S') s = 1;
        if (ss[i] == 'E') e = 1;
        if (ss[i] == 'N') n = 1;
    }
    (n == s && w == e) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}