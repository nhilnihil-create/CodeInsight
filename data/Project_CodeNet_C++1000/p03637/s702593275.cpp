#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    int num_4 = 0;
    int num_2 = 0;
    int odd = 0;
    rep(i, n)
    {
        ll a;
        cin >> a;
        if (a > 4)
        {
            if (a % 4 == 0)
            {
                num_4++;
            }
            else if (a % 2 == 0)
            {
                num_2++;
            }
            else
                odd++;
        }
        else if (a == 2)
        {
            num_2++;
        }
        else if (a == 4)
        {
            num_4++;
        }
        else
            odd++;
    }
    if (odd == 0 || num_4 >= odd || (num_4 + 1 == odd && num_2 == 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}