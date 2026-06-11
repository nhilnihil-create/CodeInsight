#include<bits/stdc++.h>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    int xmin = 0, xmax = w, ymin = 0, ymax = h;
    for(int i = 0; i < n; i++){
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1) if(xmin < x) xmin = x;
        if(a == 2) if(xmax > x) xmax = x;
        if(a == 3) if(ymin < y) ymin = y;
        if(a == 4) if(ymax > y) ymax = y;
    }
    if(xmax - xmin > 0 && ymax - ymin > 0){
        cout << (xmax - xmin) * (ymax - ymin) << endl;
    }
    else cout << 0 << endl;
}