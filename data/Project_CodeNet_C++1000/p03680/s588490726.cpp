#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int spawn = 0;
    for (int i = 0; i < n; i++) {
        spawn = a.at(spawn) - 1;

        if (spawn == 1) {
            cout << i + 1 << endl;
            break;
        }

        if (i >= n - 1) {
            cout << -1 << endl;
        }
    }
}