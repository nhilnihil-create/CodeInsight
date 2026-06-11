#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    if((x > 0 && y > 0) || (x < 0 && y < 0)){
        ans += fabs(y - x);
        if(x > y){
            ans += 2;
        }
    }else{
        if(x == 0){
            if(y > 0) ans += fabs(y - x);
            if(y < 0) ans += (fabs(y - x) + 1);
        }else if(y == 0){
            if(x > y) ans += (fabs(y - x) + 1);
            if(x < y) ans += (fabs(y - x));
        }else{
            ans += (fabs(y - (-x)) + 1);
        }
    }
    cout << ans << endl;
    return 0;
}