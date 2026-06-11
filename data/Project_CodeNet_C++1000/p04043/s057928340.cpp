#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    vector<int> a;
    int x, y, z;
    cin >> x >> y >> z;
    a.push_back(x);
    a.push_back(y);
    a.push_back(z);
    sort(a.begin(), a.end());
    if (a[0] == 5 && a[1] == 5 && a[2] == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
