#include <bits/stdc++.h>

using namespace std;

bool sameSet(int x, int y, const set<int> &s) {
    return s.find(x) != s.end() && s.find(y) != s.end();
};

int main() {
    int x, y;
    cin >> x >> y;
    set<int> s1{1, 3, 5, 7, 8, 10, 12}, s2{4, 6, 9, 11}, s3{2};

    if (sameSet(x, y, s1) || sameSet(x, y, s2) || sameSet(x, y, s3)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}