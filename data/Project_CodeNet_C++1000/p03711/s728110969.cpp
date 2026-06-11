#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<int> g1 {1, 3, 5, 7, 8, 10, 12};
    vector<int> g2 {4, 6, 9, 11};
    int x, y;
    cin >> x >> y;

    if (find(g1.begin(), g1.end(), x) != g1.end() && find(g1.begin(), g1.end(), y) != g1.end()) {
        cout << "Yes" << endl;
    } else if (find(g2.begin(), g2.end(), x) != g2.end() && find(g2.begin(), g2.end(), y) != g2.end()) {
        cout << "Yes" << endl;
    } else if (x == 2 && y == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}