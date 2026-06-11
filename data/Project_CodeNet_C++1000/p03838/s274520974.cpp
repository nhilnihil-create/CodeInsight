#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y; cin >> x >> y;
    cout << min( abs(x - y) + (x > y ? 2 : 0), abs(x + y) + 1 ) << endl;
}