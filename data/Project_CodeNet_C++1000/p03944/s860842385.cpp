#include <bits/stdc++.h>
using namespace std;

int main(){
    int w,h,n;
    cin >> w >> h >> n;
    int wl=0,wr=w,hu=h,hd=0;
    for(int ix=0;ix<n;ix++){
        int x,y,a; cin >> x >> y >> a;
        if(a == 1){
            wl = max(wl,x);
        }
        if(a == 2){
            wr = min(wr,x);
        }
        if(a == 3){
            hd = max(hd,y);
        }
        if(a == 4){
            hu = min(hu,y);
        }
    }
    if(wl>wr) wl=wr=0;
    if(hd>hu) hu=hd=0;
    cout << (wr-wl)*(hu-hd) << endl;
}