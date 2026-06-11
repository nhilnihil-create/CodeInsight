#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, p; cin >> n >> p;
    vector<int> a(n);
    int m = 0;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0) {
            m++;
        }
    }
    if (n == m) {
        if (p == 0) {
            cout << ((Int)1<<(n)) << endl;
        }
        else {
            cout << 0 << endl;
        }
        return 0;
    }
    cout << ((Int)1<<(n-1)) << endl;
}
