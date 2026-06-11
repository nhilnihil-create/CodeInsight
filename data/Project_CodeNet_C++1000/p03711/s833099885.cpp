#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, d30 = 0, d31 = 0, d29 = 0;
    cin >> x >> y;
    if (x == 2) d29++;
    else if (x == 4 || x == 6 || x == 9 || x == 11) d30++;
    else d31++;
    if (y == 2) d29++;
    else if (y == 4 || y == 6 || y == 9 || y == 11) d30++;
    else d31++;
    if (d30 == 2 || d31 == 2) cout << "Yes";
    else cout << "No";
}