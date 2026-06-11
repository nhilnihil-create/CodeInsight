#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < 0) {
        if (b < 0) {
            if ((b - a) % 2) {
                cout << "Positive\n";
            } else {
                cout << "Negative\n";
            }
        } else {
            cout << "Zero\n";
        }
    } else if (a == 0) {
        cout << "Zero\n";
    } else {
        cout << "Positive\n";
    }
}