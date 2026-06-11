#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string s;
    cin >> s;

    int slen = s.size() - 2;
    string t = to_string(slen);

    cout << s.substr(0, 1) + t + s.substr(s.size() - 1, 1) << endl;

}
