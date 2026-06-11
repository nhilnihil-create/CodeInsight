#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        d.at(i) = x;
    }
    int count = 0, a = 0;
    for (;;) {
        if (a == 1) {
            cout << count << endl;
            break;
        }
        if (count >= n) {
            cout << "-1" << endl;
            break;
        }
        count++;
        a = d.at(a);
        a = a - 1;
    }
}