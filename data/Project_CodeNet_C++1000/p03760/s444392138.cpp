#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string O, E;
    cin >> O >> E;
    string pass;
    rep(i,min(O.size(),E.size())) {
        pass.push_back(O.at(i));
        pass.push_back(E.at(i));
    }
    if (O.size() != E.size()) {
        pass.push_back(O.at(O.size() - 1));
    }
    cout << pass << endl;
}
