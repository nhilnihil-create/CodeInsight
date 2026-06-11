#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    string s; cin >> s;
    cout << s.at(0) << s.size()-2 << s.at(s.size()-1) << endl;
}