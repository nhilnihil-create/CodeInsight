#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x ,y;
    cin >> x >> y;

    ll ans = 0;
    
    if(x >= 0 && y >= 0){
        ans = abs(y - x);
        if(y <= x){
            if(y == 0){
                ans++;
            }else{
                ans += 2;
            }
        }
    }else if(x < 0 && y < 0){
        ans = abs(y - x);
        if(y <= x){
            ans += 2;
        }
    }else{
        if(x <= y){
            ans = abs(y - x);
            ll k = 0 - x;
            ll cou = 1;
            cou += abs(y - k);

            if(ans > cou){
                ans = cou;
            }
        }else{
            ans = abs(y - x);
            ans++;
            ll k = 0 - x;
            ll cou = 1;
            cou += abs(y - k);

            if(ans > cou){
                ans = cou;
            }
        }
    }

    cout << ans << endl;
}