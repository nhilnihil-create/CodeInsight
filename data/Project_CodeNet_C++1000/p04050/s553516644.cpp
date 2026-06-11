#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        if (a[i] % 2 == 1) {
            swap(a[i], a[0]);
        }
    }
    for (int i = 1; i < m; i++) {
        if (a[i] % 2 == 1) {
            swap(a[i], a[m - 1]);
        }
    }
    for (int i = 1; i < m - 1; i++) {
        if (a[i] % 2 == 1) {
            cout << "Impossible\n";
            return 0;
        }
    }
    vector<int> b = a;
    b[0]--;
    if (a[0] % 2 == 0 || m == 1) {
        b.push_back(1);
    } else {
        b.back()++;
    }
    vector<int> bb;
    for (int x : b)
        if (x > 0) bb.push_back(x);
    b = bb;
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
    cout << b.size() << "\n";
    for (int x : b) {
        cout << x << " ";
    }

    return 0;
}