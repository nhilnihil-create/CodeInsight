#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    int W, H, N;
    int x, y, a;
    cin >> W >> H >> N;

    int minx = 0, maxx=W;
    int miny = 0, maxy=H;
    
    rep(i, N){
        cin >> x >> y >> a;
        if(a==1){
            minx = max(minx, x);
        }else if(a==2){
            maxx = min(maxx, x);
        }else if(a==3){
            miny = max(miny, y);
        }else if(a==4){
            maxy = min(maxy, y);
        }
    }
    // cout << maxy << endl;
    // cout << miny << endl;
    // cout << maxx << endl;
    // cout << minx << endl;

    if(maxy < miny || maxx < minx){
        cout << 0 << endl;
    }else{
        cout << (maxy-miny)*(maxx-minx) << endl;
    }

    return 0;
}