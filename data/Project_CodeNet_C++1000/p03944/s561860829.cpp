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

ll mygcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return mygcd(b, a % b);
    }
}

signed main()
{
    int w,h,n;
    cin >> w >> h >> n;
    int xmin=0;
    int xmax=w;
    int ymin=0;
    int ymax=h;
    rep(i,n){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1){
            chmax(xmin, x);
        }
        else if(a==2){
            chmin(xmax, x);
        }
        else if(a==3){
            chmax(ymin, y);
        }
        else {
            chmin(ymax, y);
        }
    }
    if(xmin>=xmax || ymin>=ymax){
        cout << 0 << endl;
    }
    else {
        cout << (xmax - xmin) * (ymax - ymin) << endl;
    }

    return 0;
}