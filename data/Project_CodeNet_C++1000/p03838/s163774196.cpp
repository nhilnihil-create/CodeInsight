#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll x,y;
    ll ans=0;
    cin >> x >> y;
    ll a = abs(y) - abs(x);
    if(a>0){
        if(x<0){
            ans++;
            x*= -1;
        }
        x += a;
        ans += a;
        if(x != y) ans++;

    }
    else if(a<0){
        if(x>0){
            ans++;
            x*= -1;
        }
        x -= a;
        ans += -a;
         if(x != y) ans++;
    }
    else{
         if(x != y) ans++;
    }
    cout << ans << endl;
}