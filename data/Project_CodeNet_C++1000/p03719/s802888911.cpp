#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (c >= a && c <= b) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}