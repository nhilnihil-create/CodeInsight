#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 'H';
    }
    if (a != b) {
        cout << "D";
    }
}
