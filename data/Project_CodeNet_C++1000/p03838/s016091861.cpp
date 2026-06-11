#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;


int main() {
    ll x,y;
    cin >> x >> y;
    ll ans = 0;
    ll val_x = -x;
    ll val_y = -y;
    if(x >= 0 && y > 0){
        if(x <= y){
            ans = y - x;
        }
        else{
            ans = x - y + 2;
        }
    }
    else if(x >= 0 && y == 0){
        ans = x + 1;
    }
    else if(x >= 0 && y < 0){
        
        if(x <= val_y){// 3 -5
            ans = val_y - x + 1;
        }
        else{ //5 -3
            ans = x - val_y + 1;
        }        
    }
    else if(x < 0 && y > 0){
        
        if(val_x <= y){// -3 5
            ans = y - val_x + 1;
        }
        else{// -5 3
            ans = val_x - y + 1;
        }           
    }
    else if(x < 0 && y == 0){
        ans = val_x - y;
    }
    else{
        if(val_x <= val_y){//-3 -5
            ans = val_y - val_x + 2;
        }
        else{//-5 -3
            ans = val_x - val_y;
        }           
    }

    cout << ans << endl;
}