#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    map<char, int> ma;
    string s;
    cin >> s;
    rep(i, s.size()) { ma[s[i]]++; }

    if (ma['W'] > 0 && ma['E'] == 0) {
        cout << "No" << endl;
    } else if (ma['E'] > 0 && ma['W'] == 0) {
        cout << "No" << endl;
    } else if (ma['N'] > 0 && ma['S'] == 0) {
        cout << "No" << endl;
    } else if (ma['N'] == 0 && ma['S'] > 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}