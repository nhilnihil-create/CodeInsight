//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
int main(){
    long long w, h, n, i, x[1010], y[1010], a[1010], lef, rig, up, down, ans, high, width;
    cin >> w >> h >> n;
    lef=0;rig=w;up=h;down=0;
    for(i=0;i<n;i++){
        cin >> x[i] >> y[i] >> a[i];
    }

    for(i=0;i<n;i++){
        if(a[i]==1 && x[i]>lef) lef=x[i];
        if(a[i]==2 && x[i]<rig) rig=x[i];
        if(a[i]==3 && y[i]>down) down=y[i];
        if(a[i]==4 && y[i]<up) up=y[i]; 
    }
    
    width=rig-lef;
    high=up-down;
    ans=high*width;
    if(width<=0 || high<=0) ans=0;
    cout << ans <<endl;
    return 0; 
}