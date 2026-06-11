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

    if (a + b < 10)
    {
        cout << a + b << '\n';
    }
    else
    {
        cout << "error" << '\n';
    }
    return 0;
}
