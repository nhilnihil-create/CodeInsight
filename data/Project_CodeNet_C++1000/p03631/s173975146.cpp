#include <iostream>

using namespace std;

int main() {
    string n, m;
    cin >> n;
    m = n;
    reverse(m.begin(), m.end());
    if (m == n) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}