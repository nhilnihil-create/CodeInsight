#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}

ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}

int main(){
    int n;
    cin>>n;
    ll ans=1;
    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        ans=lcm(ans,t);
    }
    cout<<ans<<endl;
}