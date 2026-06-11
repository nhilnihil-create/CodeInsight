#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int64_t x;
    cin >> x;
    int64_t mod11, div11, ans = 0;
    div11 = (x) / 11;
    mod11 = (x) % 11;
    if (x <= 6)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (x <= 11)
    {
        cout << 2 << endl;
        return 0;
    }
    //    ans = 1;
    if (mod11 == 0)
    {
        ans = 0;
    }
    else if (mod11 <= 6)
    {
        ans = 1;
    }
    else
    {
        ans = 2;
    }
    ans = ans + div11 * 2;
    cout << ans << endl;
}