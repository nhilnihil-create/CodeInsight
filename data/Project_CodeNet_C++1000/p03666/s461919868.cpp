#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    ll N,A,B,C,D;cin>>N>>A>>B>>C>>D;
    ll M=abs(A-B),dif=(D-C);
    bool flag=false;
    for(ll i=0;i<=N-1;i++){
        ll a=C*i+(-C)*(N-1-i);
        if(a==M){
            flag=true;
        }
        else if(a>M){
            if(M+dif*(N-1-i)>=a){
                flag=true;
            }
        }else if(a<M){
            if(a+dif*i>=M) {
                flag=true;
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
