#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll x;
    cin>>x;
    ll ans=0;
    ll flag=0;
    for(ll i=0;i<1e9;++i){
        if(flag >= x){
            break;
        }
        flag += i;
        ans++;
    }
    cout<<ans-1<<endl;

    return 0;
}