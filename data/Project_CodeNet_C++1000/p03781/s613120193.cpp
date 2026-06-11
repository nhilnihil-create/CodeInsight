#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x,ans;
    cin >> x;
    for(ll i=0;i<=x;i++){
        if(i*(i+1)/2>=x){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}