#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n5 = 0, n7 = 0;
    cin >> a >> b >> c;
    if (a == 5) n5 ++;
    if (a == 7) n7 ++;
    if (b == 5) n5 ++;
    if (b == 7) n7 ++;
    if (c == 5) n5 ++;
    if (c == 7) n7 ++;
    if (n5 == 2 && n7 == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}