#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a,b,c,d;
ll n;
int main(void){
    cin>>a>>b>>c>>d>>n;
    a=a*8; b=b*4; c=c*2;
    ll t=min({a,b,c,d});
    if(t==d){
        if(n%2==0){
            cout<<t*n/2<<endl;
        }else{
            ll u=min({a,b,c});
            cout<<t*(n-1)/2+u/2<<endl;
        }
    }else{
        cout<<t/2*n<<endl;
    }

}

