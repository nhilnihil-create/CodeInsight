#include<bits/stdc++.h>
using namespace std;

int main(){
    int w, h, n; cin >> w >> h >> n;
    vector<int> x(100), y(100), a(100);
    int x0=0, x1=w, y0=0, y1=h;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> a[i];

        if(a[i]==1){
            x0 = max(x0, x[i]);
        }else if(a[i]==2){
            x1 = min(x1, x[i]);
        }else if(a[i]==3){
            y0 = max(y0, y[i]);
        }else if(a[i]==4){
            y1 = min(y1, y[i]);
        }
    }
    int ans = max(x1-x0, 0)*max(y1-y0, 0);
    cout << ans << endl;
    return 0;

}