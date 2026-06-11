
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    // (nx-zx)*(ny-zy)が白い部分の面積になる
    int zx =0,nx = w,zy =0,ny=h;

    rep(i,n){
        int x,y,a;
        cin >> x >> y >> a;
        // a=1ならxより左側を黒くする(zxがずれる)
        if(a ==1) zx=max(zx,x);
        // a=2ならxより右側を黒くする(zxがずれる)
        else if(a ==2) nx =min(nx,x);
        // a=3ならyより下側を黒くする(zxがずれる)
        else if(a ==3) zy = max(zy,y);
        // a=4ならyより上側を黒くする(zxがずれる)
        else ny = min(ny,y);
    }
    cout << max(nx-zx,0) * max(ny-zy,0) << endl;

    
}