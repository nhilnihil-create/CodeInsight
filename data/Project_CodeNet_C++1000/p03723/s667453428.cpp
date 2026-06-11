#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int func(int a, int b, int c) {
    if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
        return 0;

    if (a == b && b == c)
        return -1;

    return func((b + c) / 2, (a + c) / 2, (a + b) / 2) + 1;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << func(a, b, c) << endl;
}
