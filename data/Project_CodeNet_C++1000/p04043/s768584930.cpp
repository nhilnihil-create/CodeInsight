#include <bits/stdc++.h>

using namespace std;

int main() {
    int five = 0;
    int seven = 0;
    for (int i = 0; i < 3; i++) {
        int temp;
        cin >> temp;
        if (temp == 5) {
            five++;
        } else if (temp == 7) {
            seven++;
        }
    }
    if (five == 2 && seven == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}