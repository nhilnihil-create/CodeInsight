#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    ll mod=1e9+7;
    ll n,m,ans1=0,ans2=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        ans1+=(2*i-n+1)*a;
    }
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        ans2+=(2*i-m+1)*a;
    }
    cout<<((ans1%mod)*(ans2%mod))%mod<<endl;
}
