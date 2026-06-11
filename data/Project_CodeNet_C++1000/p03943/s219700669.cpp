#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, k = 0;
    cin >> a >> b >> c;
    if (a == b + c || b == c + a || c == a + b) k++;
    if (k == 1) cout << "Yes";
    else cout << "No";
}