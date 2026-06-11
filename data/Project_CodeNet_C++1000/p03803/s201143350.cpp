#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b;
    cin >> a >> b;

    if (a == 1)
    {
        a *= 100;
    }
    if (b == 1)
    {
        b *= 100;
    }

    cout << (a == b ? "Draw" : a > b ? "Alice" : "Bob") << endl;
    return 0;
}
