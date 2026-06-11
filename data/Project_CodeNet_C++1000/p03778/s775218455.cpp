#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int W, a, b;
    cin >> W >> a >> b;
    int ans;

    if ((a + W) < b)
    {
        ans = b - W - a;
    }
    else if (b < a)
    {
        ans = a - (b + W);
    }
    else
    {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}
