#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    ll m,n;
    m=max(a,b);
    n=min(a,b);
    if(m%n==0) return n;
    else return gcd(m%n, n);
}

int main(){
    int n;
    cin >> n;
    ll ans=1;
    for(int i=0; i<n; i++){
        ll t;
        cin >> t;
        ans = (ans/gcd(ans, t))*t;
    }
    cout << ans << endl;
}