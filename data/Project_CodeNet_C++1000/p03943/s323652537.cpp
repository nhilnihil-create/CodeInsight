#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector < int > a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    cout << (a[0]+a[1]==a[2] ? "Yes": "No");
    return 0;
}

