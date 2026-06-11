#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a,b,c,d;
int main(void){
    cin>>n>>a>>b>>c>>d;
    ll G=b-a;
    for(int i=0;i<n;i++){
        ll A=c*i;
        ll B=d*i;
        ll C=c*(n-1-i)-G;
        ll D=d*(n-1-i)-G;
        if(A>D||C>B){
            
        }else{
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    
}
