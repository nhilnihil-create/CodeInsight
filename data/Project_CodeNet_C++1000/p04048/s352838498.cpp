#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll f(ll a, ll b){
    if(a>b) swap(a, b);
    ll d = b/a;
    if(b%a==0) return (2*d - 1)*a;
    else return 2*d*a+f(a, b%a);
}
int main(){
    ll n, x; cin>>n>>x;
    cout<<n+f(x, n-x)<<endl;
}