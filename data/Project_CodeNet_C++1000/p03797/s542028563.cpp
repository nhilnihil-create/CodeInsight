#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
int main(void){
    cin>>n>>m;
    ll l=0,r=1000000000000000,M=(l+r)/2;
    while(r-l>1){
        if(2*M<=m&&n+(m-2*M)/2>=M){
            l=M;
            M=(l+r)/2;
        }else{
            r=M;
            M=(l+r)/2;
        }
    }
    cout<<l<<endl;

}

