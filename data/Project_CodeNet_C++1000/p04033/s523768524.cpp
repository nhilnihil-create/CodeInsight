#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Y cout << "YES\n"
#define N cout << "NO\n"
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define R(i, n) for (int i = 0; i < n; i++)

int main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    if (a > 0)
    {
        cout << "Positive\n";
    }
    else if (a <= 0 && b >= 0)
    {
        cout << "Zero\n";
    }
    else
    {
        ans = b - a;
        if (ans % 2)
        {
            cout << "Positive\n";
        }
        else
        {
            cout << "Negative\n";
        }
    }
}