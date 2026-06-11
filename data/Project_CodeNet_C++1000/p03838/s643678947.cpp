#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;

int main(){
    ll x, y; cin >> x >> y;
    ll ans = 0;
    if(x == 0 || y == 0){
        if(x == 0 && y == 0) {cout << 0 << endl; return 0;}
        if(x == 0){
            if(y < 0) {cout << abs(y) + 1 << endl; return 0;}
            else if(y > 0) {cout << y << endl;return 0;}
        }
        else if(y == 0){
            if(x < 0) {cout << -x << endl; return 0;}
            else if(x > 0) {cout << abs(x) + 1 << endl;return 0;}
        }
        
    }
    if(x < y){
        if(0 < x) ans = y-x;
        else if(x < 0 && 0 < y){
            if(abs(x) <= abs(y)) ans = 1+abs(abs(x)-abs(y));
            else ans = abs(abs(x)-abs(y))+1;
        }
        else if(y < 0) ans = abs(abs(x)-abs(y));
        
    }

    else if(y < x){
        if(0 < y) {
            ans = abs(x-y) + 2;
        }
        else if(y < 0 && 0 < x) {
            /*if(abs(x) < abs(y))*/ ans = 1+ abs(abs(y) - abs(x));
            //else ans = 1 + abs(abs(x) - abs(y));
        }
        else if(x < 0) ans = 1 + abs(abs(y) - abs(x)) + 1;
    }  
    cout << ans << endl;
}
