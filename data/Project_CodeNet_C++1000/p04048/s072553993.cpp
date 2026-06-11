#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll a, ll b){
    if(a>b)swap(a,b);
    if(b%a==0)return b+b-a;
    ll trt = b/a;
    return 2*a*trt+f(b%a,a);
}
int main(){
    ll n,x;
    cin>>n>>x;
    cout<<n+f(n-x,x)<<endl;
    return 0;
}
