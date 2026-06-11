#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int a, b, x, count = 0, z, v, m;

    cin >> a >> b >> x;

    z = a/x;
    v = b/x;

    m = v - z;

    if(a % x == 0)
    {
        m++;
    }

    cout << m;
}
