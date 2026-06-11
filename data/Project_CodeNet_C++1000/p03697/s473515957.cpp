// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

// --------------------------------------------------------------------------------

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a + b >= 10)
        cout << "error" << endl;
    else
        cout << a + b << endl;
}

// --------------------------------------------------------------------------------

int main()
{
    // srand((unsigned)time(NULL));
    // int bt = clock();
    solve();
    // double et = 1.0 * (clock() - bt) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}