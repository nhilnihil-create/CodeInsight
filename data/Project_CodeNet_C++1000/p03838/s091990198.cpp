#include<iostream>
using namespace std;
using ll = long long;

int main(){
    ll x,y;
    cin>>x>>y;
    ll ans=1e10;
    for(int i=0;i<(1<<2);i++){
        ll r=0,a=x,b=y;
        for(int j=0;j<2;j++){
            if(i&(1<<j)){
                if(j==0) a=-a,r++;
                if(j==1) b=-b,r++;
            }
        }
        if(a<=b) ans=min(r+b-a,ans);
    }
    cout<<ans<<endl;
}