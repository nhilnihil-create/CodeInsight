#include <iostream>
using namespace std;

int main() {
    pair<int, int> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    pair<int, int> x, y;
    x = min(a, b);
    y = max(a, b);
    if (x.second < y.first) cout << 0 << endl;
    else if (x.second > y.second) cout << y.second - y.first << endl;
    else cout << x.second - y.first << endl;
}