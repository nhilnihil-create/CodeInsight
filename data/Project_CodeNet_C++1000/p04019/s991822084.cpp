#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string s;
    map<char, int>mp;
    cin >> s;
    for (auto ss : s)mp[ss]++;
    int a = mp['N'];
    int b = mp['S'];
    int c = mp['E'];
    int d = mp['W'];
    bool ans = false;
    if (a > 0 && b > 0 && c == 0 && d == 0)ans = true;
    if (c > 0 && d > 0 && a == 0 && b == 0)ans = true;
    if (a > 0 && b > 0 && c > 0 && d > 0)ans = true;
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}