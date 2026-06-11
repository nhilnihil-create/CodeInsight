#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    set<int> a;
    rep(i, 3) {
        int x;
        cin >> x;
        a.insert(x);
    }

    cout << a.size() << endl;
    return 0;
}
