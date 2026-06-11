#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i,s.size()) ++mp[s.at(i)];
    for (auto x : mp) {
        if (x.second % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

