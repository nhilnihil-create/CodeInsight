#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {

    int w,h,n; cin >> w >> h >> n;
    int xl = 0, yl = 0, xr = w, yr = h;
    int x,y,a;

    rep(i,n){
        cin >> x >> y >> a;
        if(a == 1)xl = max(xl,x);
        if(a == 2)xr = min(xr,x);
        if(a == 3)yl = max(yl,y);
        if(a == 4)yr = min(yr,y);
    }

    if((xr-xl)<0 || (yr-yl)<0) cout << 0;
    else cout << (xr-xl)*(yr-yl);


    return 0;
}
