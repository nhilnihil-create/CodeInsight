    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    using namespace std;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
     
        int h, w, d;
        cin >> h >> w >> d;
     
        char c[502];
        c[w] = '\n';
        c[w + 1] = 0;
     
        for (int i = 0; i < h; i++) {
            int x = h - i + d - h % d;
            for (int j = 0; j < w; j++) {
                c[j] = "YBGR"[(i + j) / d % 2 + (x + j) / d % 2 * 2];
            }
            cout << c;
        }
     
        return 0;
    }