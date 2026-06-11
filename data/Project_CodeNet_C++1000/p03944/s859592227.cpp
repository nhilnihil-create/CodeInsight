#include <bits/stdc++.h>
using namespace std;
int main(void){
    int w, h , n;
    cin >> w >> h >> n;
    
    int minX, minY;
    minX = minY = 0;
    int maxX = w;
    int maxY = h;
    
    for (int i=0; i<n; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) minX = max(minX, x);
        if (a == 2) maxX = min(maxX, x);
        if (a == 3) minY = max(minY, y);
        if (a == 4) maxY = min(maxY, y);
    }
    
    cout << max(0,(maxX - minX)) * max(0, (maxY - minY)) << endl;
}
