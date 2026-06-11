#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> c(h);
    rep(i,h) {
        cin >> c.at(i);
    }

    rep(i,h) {
        cout << c.at(i) << endl;
        cout << c.at(i) << endl;
    }

    return 0;
}