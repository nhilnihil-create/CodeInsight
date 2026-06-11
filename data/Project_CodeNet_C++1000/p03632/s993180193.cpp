#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a <= c && c <= b && b <= d)
    {
        cout << b - c << endl;
        return 0;
    }
    if (a <= c && c <= b && b > d)
    {
        cout << d - c << endl;
        return 0;
    }
    if (c <= a && a <= d && b < d)
    {
        cout << b - a << endl;
        return 0;
    }
    if (a >= c && a <= d && b >= d)
    {
        cout << d - a << endl;
        return 0;
    }
    cout << 0 << endl;

    return 0;
}
