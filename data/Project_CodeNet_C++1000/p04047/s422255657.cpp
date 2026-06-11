#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n;
int l[N * 2];
int main()
{
    cin >> n;
    for (int i = 0; i < 2 * n; i ++ ) cin >> l[i];
    sort(l, l + n * 2);

    int res = 0;
    for (int i = 0; i < 2 * n - 1; i += 2)
        res += min(l[i], l[i + 1]);

    cout << res << endl;

    return 0;
}