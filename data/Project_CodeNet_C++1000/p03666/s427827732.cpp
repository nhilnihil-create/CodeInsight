#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    
    for(ll i=0;i<N;i++){
        ll max=A+i*D-(N-1-i)*C;
        ll min=A+i*C-(N-1-i)*D;
        if(min<=B && B<=max){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}