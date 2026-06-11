#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    int x_min=0, y_min=0, x_max=W, y_max=H;
    for (int i=0; i<N; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if (z==1){
            x_min=max(x_min, x);
        }
        if (z==2){
            x_max=min(x_max, x);
        }
        if (z==3){
            y_min=max(y_min, y);
        }
        if (z==4){
            y_max=min(y_max, y);
        }
    }
    int ans=(y_max-y_min)*(x_max-x_min);
    if (y_max-y_min<0 && x_max-x_min<0) ans=0;
    if (ans<0) ans=0;
    cout << ans << endl;
}
