#include <iostream>
using namespace std;

int main(){
    int n,k,x,a,b,ans=0;
    
    cin>>n>>k;
    
    for(int i=1;i<=n;i++){
        cin>>x;
        a=x;
        b=k-x;
        if(a<b)
            ans+=a;
        else
            ans+=b;
    }
    cout<<2*ans<<endl;
}
