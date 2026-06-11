//  すぬけ君の塗り絵 2 イージー  WA
#include <bits/stdc++.h>
using namespace std;

int main(){
    int W, H, N;
    cin >> W >> H >> N;
    int x[N], y[N], a[N];
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i] >> a[i];
    }
    int xl=0, yd=0;
    int xr=W, yu=H;
    for(int i=0; i<N; i++){
        if(a[i]==1){
            xl=max(xl, x[i]);
        }
        if(a[i]==2){
            xr=min(xr, x[i]);
        }
        if(a[i]==3){
            yd=max(yd, y[i]);
        }
        if(a[i]==4){
            yu=min(yu, y[i]);
        }
    }
    
    int s=max(0, xr-xl)*max(0, yu-yd);
    cout << s << endl;
    return 0;
}