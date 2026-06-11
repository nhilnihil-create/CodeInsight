#include <iostream>

using namespace std;

void No() {
    cout << "No" << endl;
    exit(0);
}

void Yes() {
    cout << "Yes" << endl;
    exit(0);
}

int main() {
    int n;
    cin >> n;
    int m[4] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x & 0b11]++;
    }

    if (m[2] == 0) {
        if (m[1] + m[3] <= m[0] + 1) {
            Yes();
        } else {
            No();
        }
    } else {
        if (m[1] + m[3] <= m[0]) {
            Yes();
        } else {
            No();
        }
    }
}
