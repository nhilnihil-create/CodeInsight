#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int a[3];
int main() {
    rep(i,3) cin >> a[i];
    sort(a,a+3);
    if (a[0] == 5 && a[1] == 5 && a[2] == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}