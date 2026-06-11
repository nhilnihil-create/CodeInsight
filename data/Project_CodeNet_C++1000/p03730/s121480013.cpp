#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool flg = false;

    int n = abs(a - b);
    int d = abs(a - b);

    while (n != 0)
    {
        // cout << n << endl;
        if (n == c)
        {
            flg = true;
            break;
        }
        if (n >= a)
        {
            n = (n - a) % b;
        }
        else
        {
            n = (n + d) % b;
        }
    }

    if (flg)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
