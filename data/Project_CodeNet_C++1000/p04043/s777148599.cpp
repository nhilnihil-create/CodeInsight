#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

vector<int> a(3);
int main() {
    rep(i,3) cin >> a[i];
    sort(all(a));
    if (a.at(0) == 5 && a.at(1) == 5 && a.at(2) == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}