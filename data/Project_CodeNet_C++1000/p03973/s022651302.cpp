#include <iostream>
using namespace std;
int main()
{
    long long n, a, m = 0, r = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a < m + 2)
        {
            m = max(a, m);
            continue;
        }
        r += (a - 1) / (m + 1), m += m == 0;
    }
    cout << r << endl;
    return 0;
}