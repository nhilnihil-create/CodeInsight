#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int n, a, b,c;
    cin >> n;
    a = (int)n / 100;
    b = (int)(n - a * 100) / 10;
    c = n - 100 * a - 10 * b;
    cout << (a == c ? "Yes" : "No") << "\n";

    return 0;
}
