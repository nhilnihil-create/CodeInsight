#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    a.at(0) = 1;
    for (int i = 1; i < n; i++) {
        a.at(i) = a.at(i - 1) + n;
    }
    b.at(n - 1) = 1;
    for (int i = n - 2; i >= 0; i--) {
        b.at(i) = b.at(i + 1) + n;
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        a.at(p) += i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a.at(i));
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        printf("%d ", b.at(i));
    }
    cout << endl;
}