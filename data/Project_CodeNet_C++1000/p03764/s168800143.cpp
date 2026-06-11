#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int main(){
    ll p=0,q=0,x,y,n;
    int a,b,c,i;
    cin>>a>>b;
    for(i = 0;i < a;i++){
        cin>>n;
        p = p+n*(i)-n*(a-i-1);
        p = p%mod;
    }
    for(i = 0;i < b;i++){
        cin>>n;
        q = q+n*(i)-n*(b-i-1);
        q = q%mod;
    }
    
    cout<<p*q%mod<<endl;;
}
