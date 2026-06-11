#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;

int main(){
    ll a[7];
    for(int i=0;i<7;i++){
        cin >> a[i];
    }
    ll ans = a[1];
    if(a[0]>0 && a[3]>0 && a[4]>0 && a[0]%2+a[3]%2+a[4]%2 >= 2){
        ans += 3;
        a[0]--;
        a[3]--;
        a[4]--;
    }
    ans += a[0]/2*2;
    ans += a[3]/2*2;
    ans += a[4]/2*2;
    cout << ans << endl;
    return 0;
}