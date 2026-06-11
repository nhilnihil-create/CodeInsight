#include <iostream>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;
typedef long long ll;


const int mod=1000000007;

ll perm(ll num){
    ll n=1;
    for(ll i=num;i>0;--i){
        n=i*n%mod;
    }
    return n;
}

int main(){
    
    ll N,M;
    cin>>N>>M;
    
    ll ans=0;
    
    if(abs(N-M)==1){
        ans=perm(N)*perm(M)%mod;
    }else if(N==M){
        ans=perm(N)*perm(N)*2%mod;
    }
   
    cout<<ans<<endl;
    
    
}
