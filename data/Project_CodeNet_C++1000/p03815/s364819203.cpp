#include <bits/stdc++.h>
using namespace std;
int main() {
    long long x, a = 0;
    cin >> x;
    a += (x / 11) * 2;
    x %= 11;
    if (x > 6) a += 2;
    else if (x > 0) a++;
    cout << a;
}