#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REP_(i, a, b) for(int i = a; i <= b; i++)
#define sl(n) scanf("%lld", &n);
#define si(n) scanf("%d", &n);
#define RepAll(a) for(auto x: a)
#define cout(ans) cout << ans << endl;
typedef long long ll;
/**
 *    This code has been written by YueGuang, feel free to ask me question. Blog: http://www.yx.telstudy.xyz
 *    created:
 */
 const int mod = 1e9+7;
using namespace std;
//求解所有能组成的矩形的和再取mod
/*
    x1,y1 x5,y5
 xi -  xj , yl - yk
 xi -  xj) * (yl - yk
*/
#define N 100010
ll x[N], y[N];
ll xx, yy, maxy;
int main(){
    int n, m;

    cin >> n >> m;
  //  long long *x = long long new [n];
   // long long *y = long long new [m];

    REP(i, 0, n){
        cin >> x[i];
        /*if(i == 0){
            minx = x;
            maxx = x;
        }
        minx = min(minx, x);
        maxx = max(maxx, x);
        */
    }
    REP(i, 0, m){
        cin >> y[i];
        /*if(i == 0){
            miny = y;
            maxy = y;
        }
        miny = min(miny, y);
        maxy = max(maxy, y);
        */
    }
    //计算每个边长对面积,类似于边权？
    //cout << (maxx - minx);
    //cout << '\n' <<(maxy - miny);
    //cout << ((maxx - minx)%mod * (maxy - miny)%mod)%mod << '\n';
    //REP(i, 0, m){ }
    //yy = (yy % mod; + (y[i] - y[m - i])% mod) * (m - 2*i) % mod;
    for(int i = 0, j = m-1; j > i; j--, i++){
        yy = (yy +abs (y[i] - y[j]) * (j - i))  % mod;
    }
    for(int i = 0, j = n-1; i < j; j--, i++)
    {   xx = (xx + abs(x[i] - x[j]) * (j - i))  % mod;
     }

cout << xx*yy%mod << '\n';
}
// 9 8 7 6 5
