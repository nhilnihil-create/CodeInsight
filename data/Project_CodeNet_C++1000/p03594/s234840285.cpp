#include <bits/stdc++.h>
using namespace std;
#define long long ll;

const char color[5] = "RYGB";

int main(void) {
    int h,w,d;
    int x,y;
    cin >> h >> w >> d;
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            x = (i+j)/d;
            y = (i-j+500)/d;
            cout << color[(x%2)*2+y%2];
        }
        cout << endl;
    }
    return 0;
}
