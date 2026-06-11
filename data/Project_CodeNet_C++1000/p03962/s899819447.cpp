#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int sum = 1;

    if (a != b)
    {
        sum++;
    }
    if (a != c && b != c)
    {
        sum++;
    }
    cout << sum << endl;
    return 0;
}
