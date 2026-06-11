#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int w,h,n;
    cin >> w >> h >> n;

    int x,y,a;
    int new_x,new_y;


    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> a;
        if(a == 1) new_x = max(new_x, x);
        else if(a == 2) w = min(w, x);
        else if(a == 3) new_y = max(new_y, y);
        else if(a == 4) h = min(h, y);
    }

    

    if(w-new_x<0 || h-new_y<0) {
        cout << 0 << endl;
        return 0;
    } 

    int ans = (w-new_x)*(h-new_y);
    cout << ans << endl;
    return 0;

}