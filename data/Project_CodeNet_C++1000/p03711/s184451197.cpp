#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x,y;
    unordered_set<int> b{4,6,9,11};

    cin >> x >> y;
    if((x == 2) || (y == 2)) {
        // x != yなので
        cout << "No\n";
    } else if(b.find(x) != b.end()) {
        if(b.find(y) != b.end()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if(b.find(y) == b.end()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
