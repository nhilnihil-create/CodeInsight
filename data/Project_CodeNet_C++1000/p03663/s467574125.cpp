#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

long long n;

int ask(long long x)
{
    cout << "? " << x << endl;
    string s;
    cin >> s;
    return (s == "Y");
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long l = 1e11 - 1, r = 1e12 - 1;
    while (l + 1 < r)
    {
        long long m = (l + r) / 2;
        if (ask(m)) r = m;
        else l = m;
    }
    while (r % 10 == 0) r /= 10;
    long long k = r;
    vector<int> digits;
    while (k > 0)
    {
        digits.push_back(k % 10);
        k /= 10;
    }
    sort(all(digits));
    if (digits[0] != 9)
    {
        while (1)
        {
            if (ask(r + 1))
            {
                cout << "! " << r;
                return 0;
            }
            r = 10 * r;
        }
    }
    else
    {
        while (1)
        {
            if (ask(r + 1))
            {
                cout << "! " << r / 10;
                return 0;
            }
            r = 10 * r;
        }
    }
}
