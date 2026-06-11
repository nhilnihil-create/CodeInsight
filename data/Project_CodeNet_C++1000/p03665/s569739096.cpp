#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n,p;
    ll ans;
    cin >> n >> p;
    int odd=0,even=0;
    rep(i,n){
        int a;
        cin >> a;
        if(a%2 == 0) even++;
        else odd++;
    }
    if(odd == 0){
        if(p == 0) ans = pow(2,n);
        else ans = 0;
    }
    else{
        ans = pow(2,n-1);
    }
    cout << ans << endl;
    return 0;
    
}