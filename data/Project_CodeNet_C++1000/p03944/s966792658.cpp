#include <bits/stdc++.h>
using namespace std;;

int main(){
    int w,h,n;
    cin >> w >> h >> n;
    int maxx=0,minx=w,maxy=0,miny=h;
    int x,y,a;

    for (int i = 0; i < n; i++){
        cin >> x >> y >> a;
        if (a==2){
            minx = min(x,minx);
        }else if (a==1){
            maxx = max(maxx,x);
        }else if (a==4){
            miny = min(miny,y);
        }else{
            maxy = max(maxy,y);
        }
    }
    if (minx <= maxx || miny <= maxy){
        cout << 0 << endl;
        return 0;
    }else{
        cout << (minx-maxx)*(miny-maxy) << endl;
        return 0;
    }
}