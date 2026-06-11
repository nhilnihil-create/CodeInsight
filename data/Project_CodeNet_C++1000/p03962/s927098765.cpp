#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int color;
    set<int> colors;
    rep(0, 3) {
        cin >> color;
        colors.insert(color);
    }

    cout << colors.size() << endl;

    return 0;
}
