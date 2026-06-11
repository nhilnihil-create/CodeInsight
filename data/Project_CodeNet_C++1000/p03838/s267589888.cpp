#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int x, y;
    cin >> x >> y;
    
    int ans;
    if(abs(x)==abs(y)) {
        if(x*y>=0) ans=0;
        else ans=1;
    } else if(abs(x)<abs(y)) {
        if(x*y>0) {
            ans = y>0 ? abs(y)-abs(x) : abs(y)-abs(x)+2;
        } else if(x*y<0) {
            ans = abs(y)-abs(x)+1;
        } else {
            ans = y>0 ? abs(y)-abs(x) : abs(y)-abs(x)+1;
        }
    } else {
        if(x*y>0) {
            ans = x>0 ? abs(x)-abs(y)+2 : abs(x)-abs(y);
        } else if(x*y<0) {
            ans = abs(x)-abs(y)+1;
        } else {
            ans = x>0 ? abs(x)-abs(y)+1 : abs(x)-abs(y);
        }
    }
    cout << ans << endl;

    return 0;
    
}