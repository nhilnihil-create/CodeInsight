#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
int main(){
    ll n,a,b,l,r;
    cin>>n>>a>>b>>l>>r;
    int flag = 1;
    ll x,y;
    for(ll i = 0; i <= n-1;i++){
        x = a+l*i-(n-i-1)*r;
        y = a+r*i-(n-i-1)*l;
        if(x <= b && b <= y){
            flag = 0;
        }
    }
    if(flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}