#include <iostream>
using namespace std;

void solve()
{
    int w, h, n; cin >> w >> h >> n;
    int xl = 0, xr = w, yt = h, yb = 0;
    for(int i = 0; i < n; ++i){
        int type;
        int x, y;
        cin >> x >> y >> type;
        switch(type){
            case 1:
                if(x > xl)xl = x;
                break;
            case 2:
                if(x < xr)xr = x;
                break;
            case 3:
                if(y > yb)yb = y;
                break;
            case 4:
                if(y < yt)yt = y;
                break;
        }
    }
    // cout << "xr, xl, yt, yb" << xr << " " << xl << " " << yt << " " << yb << endl;
    if(xr <= xl || yt <= yb) cout << 0 << endl;
    else cout << (yt-yb)*(xr-xl) << endl;
}

int main()
{
    solve();
    return 0;
}