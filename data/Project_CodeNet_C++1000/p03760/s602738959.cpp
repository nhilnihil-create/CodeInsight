#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string o, e;
    cin >> o;
    cin >> e;

    rep(i,(int)e.size()) {
        cout << o.at(i);
        cout << e.at(i);
    }
    if (o.size()>e.size()) {
        cout << o.at(o.size()-1);
    }

    cout << endl;
    return 0;
}