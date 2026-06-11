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

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int diffx=tx-sx;
    int diffy=ty-sy;
    rep(i,diffx){
        cout << "R";
    }
    rep(i,diffy){
        cout << "U";
    }
        rep(i,diffx){
        cout << "L";
    }
        rep(i,diffy){
        cout << "D";
    }
    cout << "D";
    rep(i,diffx+1){
        cout << "R";
    }
    rep(i, diffy+1)
    {
        cout << "U";
    }
    cout << "LU";
    rep(i, diffx+1)
    {
        cout << "L";
    }
    rep(i, diffy+1)
    {
        cout << "D";
    }
    cout << "R" << endl;

    return 0;
}