/*
      author  : nishi5451
      created : 12.08.2020 21:51:32
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll a,b,x;
    ll ans;
    cin >> a >> b >> x;
    if(a==0){
        if(b==0) ans=1;
        else ans = b/x+1;
    }
    else{
        ans = b/x-(a-1)/x;
    }
    cout << ans << endl;
    return 0;
}