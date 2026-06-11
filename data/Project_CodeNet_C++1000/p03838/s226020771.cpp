#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}
signed main()
{
    int x, y;
    cin >> x >> y;
    int diff = abs(abs(x) - abs(y));

    if (x > 0)
    {
        if (y > 0)
        {
            if (x < y)
            {
                //0 x y
                cout << diff << endl;
            }
            else
            {
                //0 y x
                cout << diff + 2 << endl;
            }
        }
        else if (y < 0)
        {
            //y 0 x
            if (-x < y)
            {
                //-x y 0 x
                cout << diff + 1 << endl;
            }
            else
            {
                //y -x 0 x
                cout << diff + 1 << endl;
            }
        }
        else
        {
            cout << diff + 1 << endl;
        }
    }
    else if (x < 0)
    {
        if (y > 0)
        {
            //x 0 y
            if (-x < y)
            {
                //x 0 -x y
                cout << 1 + diff << endl;
            }
            else
            {
                //x 0 y -x
                cout << 1 + diff << endl;
            }
        }
        else if (y < 0)
        {
            if (x < y)
            {
                //x y 0
                cout << diff << endl;
            }
            else
            {
                //y x 0
                cout << diff + 2 << endl;
            }
        }
        else
        {
            cout << diff << endl;
        }
    }
    else {
        if(y>0){
            cout << diff << endl;
        }
        else {
            cout << diff + 1 << endl;
        }
    }
    return 0;
}