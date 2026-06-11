#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
    vector<int> v(3);
    bool ans = false;
    for (int i=0; i<3; ++i) {
        cin >> v.at(i);
    }

    sort(v.begin(), v.end());

    if (v.at(0) + v.at(1) == v.at(2)) ans = true;
    
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}