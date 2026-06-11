#include <bits/stdc++.h>
using namespace std;
using Int = long long unsigned int;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    Int n,x,ans=0; cin>>n>>x; n-=x; if(x>n)swap(n,x);
    while(1){
        if(!(n%x)){ans+=n*3; break;}
        else {
            Int a=n; ans+=n/x*3*x; n=x; x=a%x;
        }
    }
    cout<<ans<<'\n';
}