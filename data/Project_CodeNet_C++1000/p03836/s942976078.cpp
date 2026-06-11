#include "bits/stdc++.h"

using namespace std;

void Main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string path = "";
    for (int i = 0; i < tx - sx; ++i) {
        path += "R";
    }
    for (int i = 0; i < ty - sy; ++i) {
        path += "U";
    }
    for (int i = 0; i < tx - sx; ++i) {
        path += "L";
    }
    for (int i = 0; i < ty - sy; ++i) {
        path += "D";
    }
    path += "D";
    for (int i = 0; i < tx - sx + 1; ++i) {
        path += "R";
    }
    for (int i = 0; i < ty - sy + 1; ++i) {
        path += "U";
    }
    path += "L";
    path += "U";
    for (int i = 0; i < tx - sx + 1; ++i) {
        path += "L";
    }
    for (int i = 0; i < ty - sy + 1; ++i) {
        path += "D";
    }
    path += "R";

    cout << path << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
