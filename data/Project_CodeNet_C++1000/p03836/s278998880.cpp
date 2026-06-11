#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;

    string ans = "";
    rep(i, dx) ans+='R';
    rep(i, dy) ans+='U';
    rep(i, dx) ans+='L';
    rep(i, dy) ans+='D';
    ans+='D';
    rep(i, dx+1) ans+='R';
    rep(i, dy+1) ans+='U';
    ans+='L';    
    ans+='U';
    rep(i, dx+1) ans+='L';
    rep(i, dy+1) ans+='D';
    ans+='R';
    
    cout << ans << endl;
}

