#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n;
    cin >> n;
    int gy = 0, br = 0, gr = 0, cy = 0, bl = 0, yl = 0, org = 0, r = 0, h = 0;
    for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
    if(x >= 1 && x <= 399) {
        gy = 1;
    }
    else if(x >= 400 && x <= 799) {
        br = 1;
    }
    else if(x >= 800 && x <= 1199) {
        gr = 1;
    }
    else if(x >= 1200 && x <= 1599) {
        cy = 1;
    }
    else if(x >= 1600 && x <= 1999) {
        bl = 1;
    }
    else if(x >= 2000 && x <= 2399) {
        yl = 1;
    }
    else if(x >= 2400 && x <= 2799) {
        org = 1;
    }
   else if(x >= 2800 && x <= 3199) {
        r = 1;
    }
    else {
        h++;
    }

    }
    int y = min(8, h);

    cout << max((gy + br + gr + cy + bl + yl + org + r), 1) << " " << gy + br + gr + cy + bl + yl + org + r + h << endl;
    return 0;
}
