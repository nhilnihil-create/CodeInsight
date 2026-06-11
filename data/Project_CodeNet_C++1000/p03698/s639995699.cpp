#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    string S;
    cin >> S;

    map<char, int> mp;
    rep(i,S.size()) ++mp[S[i]];
    for (auto x : mp) {
        if (x.second >= 2) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
} 

