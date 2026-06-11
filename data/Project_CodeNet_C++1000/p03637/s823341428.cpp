#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    cin >> n;
    ll a;
    int cnt = 0, c_2 = 0;
    rep(i, n)
    {
        cin >> a;
        if (a % 4 == 0)
        {
            cnt++;
        }
        else if (a % 2 == 0)
        {
            c_2++;
        }
    }
    int ans = n / 2;
    // cout << cnt << "," << c_2 << endl;

    if (cnt >= ans)
    {
        cout << "Yes" << endl;
    }
    else if ((cnt + c_2 / 2) >= ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
