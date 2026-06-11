#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, s1, s2, s3, d;
    cin >> a >> b;
    int s = min(a, b);
    if (a % 3 == 0 || b % 3 == 0)
    {
        cout << '0';
        return 0;
    }
    if (a % 2 == 0) s = min(s, a / 2);
    if (b % 2 == 0) s = min(s, b / 2);
    if (a % 2 == 1 && b % 2 == 1)
    {
        for (int c = 1; c < b; c++)
        {
            s1 = a * (b - c);
            s2 = (a + 1) / 2 * c;
            s3 = (a - 1) / 2 * c;
            d = max(s1, s2) - min(s1, s3);
            s = min(s, d);
        }
        for (int c = 1; c < a; c++)
        {
            s1 = b * (a - c);
            s2 = (b + 1) / 2 * c;
            s3 = (b - 1) / 2 * c;
            d = max(s1, s2) - min(s1, s3);
            s = min(s, d);
        }
    }
    cout << s;
}