#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll x, y;
    cin >> x >> y;

    ll x_ = abs(x);
    ll x_s = (x < 0) ? -1 : 1;
    ll y_ = abs(y);
    ll y_s = (y <= 0) ? -1 : 1;

    ll inc = y_ - x_;

    ll pushCnt = abs(inc);

    if (x_s * y_s < 0)
    {
        pushCnt++;
    }
    else
    {
        if (inc > 0)
        {
            if (x_s == -1)
                pushCnt += 2;
        }
        else if(inc < 0)
        {
            if (x_s == 1)
                pushCnt += 2;
        }
    }
    
    cout << pushCnt << endl;

    return 0;
}
