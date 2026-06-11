#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    ll n,m,ans=0LL; cin >> n >> m;
    if(n>=m/2LL) ans = m/2LL;
    else{
        m -= n*2LL;
        ans = n + (m/4LL);
    }
    cout << ans << endl;
}