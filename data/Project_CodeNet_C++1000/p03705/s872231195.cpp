#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    ll n,a,b;
    ll ans;
    cin >> n >> a >> b;
    if(a>b) ans=0;
    else if(n==1){
        if(a!=b) ans=0;
        else ans=1;
    }
    else{
        n = n-2;
        ans = b*n -a*n +1;
    }
    cout << ans << endl;
}