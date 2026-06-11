#include <iostream>

using namespace std;

int64_t a[100'000];
int64_t da[100'000];
int64_t c[100'000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int64_t u = (int64_t)n * (n + 1) / 2;
    int64_t s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        da[i] = a[(i + 1) % n] - a[i];
    }

    if (s % u != 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    int64_t f = s / u;
    for (int i = 0; i < n; i++)
    {
        int64_t cc = f - da[i];
        if (cc < 0 || cc % n != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        c[i] = cc / n;
    }

    int64_t csum = 0;
    for (int i = 0; i < n; i++)
    {
        csum += c[i];
    }

    if (csum == f)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}