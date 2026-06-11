#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    // Your code here!
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll ans;
    if(d<a || b<c){
        ans=0;
    }else if(a<d && d<b){
        if(c<a){
            ans=d-a;
        }else{
            ans=d-c;
        }
    }else{
        if(c<a){
            ans=b-a;
        }else{
            ans=b-c;
        }
    }
    cout<<ans<<endl;
}
