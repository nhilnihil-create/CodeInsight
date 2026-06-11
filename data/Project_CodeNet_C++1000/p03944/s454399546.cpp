#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{

    int N,H,W,cnt = 0,x0,x1,y0,y1,a,xi,yi,ans;
    cin >> W >> H >> N;

    x0 = 0;
    y0 = 0;
    x1 = W;
    y1 = H;

    rep(i, N){
        cin >> xi >> yi >> a;

        
        switch (a)
        {
        case 1:
            x0 = max(xi,x0);
            break;
        
        case 2:
            x1 = min(xi,x1);
            break;

        case 3:
            y0 = max(yi,y0);
            break; 
        default:
            y1 = min(yi,y1);
            break;
        }
    }

    ans = (x1-x0)*(y1-y0);

    if(x1-x0 < 0 || y1-y0 < 0)
        ans = 0;

    cout << ans << endl;

    return 0;
}