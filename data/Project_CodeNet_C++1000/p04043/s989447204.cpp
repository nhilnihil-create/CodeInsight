#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> a = {5, 5, 7}, b(3);
    cin >> b[0] >> b[1] >> b[2];
    sort(b.begin(), b.end());
    cout << ((b == a)? "YES" : "NO");
}