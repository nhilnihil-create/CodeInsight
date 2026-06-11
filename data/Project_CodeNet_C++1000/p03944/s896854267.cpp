#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int W, H, N;

    cin >> W >> H >> N;

    int xl=0, yl=0;
    int xh=W, yh=H;

    for(int i = 0; i < N; ++i)
    {
        int x, y, a;
        cin >> x >> y >> a;

        if(a == 1) xl = max(x, xl);
        if(a == 2) xh = min(x, xh);
        if(a == 3) yl = max(y, yl);
        if(a == 4) yh = min(y, yh);
        
    }
    if(xh-xl > 0 && yh-yl > 0) cout << (xh - xl)*(yh - yl) << endl;
    else cout << 0 << endl;

    return 0;
}

