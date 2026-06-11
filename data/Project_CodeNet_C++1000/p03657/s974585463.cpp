#include "bits/stdc++.h"

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    bool is_possible = false;
    if (a % 3 == 0) is_possible = true;
    if (b % 3 == 0) is_possible = true;
    if ((a + b) % 3 == 0) is_possible = true;

    if (is_possible) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}