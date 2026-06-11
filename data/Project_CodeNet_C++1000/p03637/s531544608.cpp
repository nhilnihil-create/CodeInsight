#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int s4 = 0, s2 = 0;

    rep(i, n)
    {
        int input;
        cin >> input;
        if (input % 4 == 0)
        {
            ++s4;
            continue;
        }
        if (input % 2 == 0)
        {
            ++s2;
            continue;
        }
    }
    n -= s4 * 2;
    if (n <= 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    n -= s2;
    if (n <= 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}