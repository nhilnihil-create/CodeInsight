#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string output = "";

    for (int i = 0; i < ty - sy; i++) {
        output += 'U';
    }
    for (int i = 0; i < tx - sx; i++) {
        output += 'R';
    }
    for (int i = 0; i < ty - sy; i++) {
        output += 'D';
    }
    for (int i = 0; i < tx - sx; i++) {
        output += 'L';
    }

    output += 'L';
    for (int i = 0; i < ty - sy + 1; i++) {
        output += 'U';
    }
    for (int i = 0; i < tx - sx + 1; i++) {
        output += 'R';
    }
    output += 'D';
    output += 'R';
    for (int i = 0; i < ty - sy + 1; i++) {
        output += 'D';
    }
    for (int i = 0; i < tx - sx + 1; i++) {
        output += 'L';
    }
    output += 'U';

    cout << output << endl;

    return 0;
}
