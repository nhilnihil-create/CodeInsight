#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    cin >> n;
    deque<int> a(n);
    int cnt5 = 0, cnt0 = 0;
    int sum = 0;

    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 10 == 0)
    {
        sort(a.begin(), a.end());
        rep(i, n)
        {
            if (a[i] % 10 != 0)
            {
                sum -= a[i];
                break;
            }
        }
        if (sum % 10 == 0)
        {
            sum = 0;
        }
    }
    cout << sum << endl;
    return 0;
}
