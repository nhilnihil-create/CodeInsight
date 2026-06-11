#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int x, a, b;
    cin >> x >> a >> b;

    if (b <= a)
        cout << "delicious" << endl;
    else if (b <= a + x)
        cout << "safe" << endl;
    else
        cout << "dangerous" << endl;
}