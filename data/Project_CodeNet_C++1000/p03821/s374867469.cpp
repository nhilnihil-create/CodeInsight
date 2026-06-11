#include<iostream>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;
    ll ab[2][100010];
    ll ans=0;
    for(int i=0;i<n;++i){
        cin>>ab[0][i]>>ab[1][i];
    }
    for(int i=n-1;i>=0;--i){
        ab[0][i]+=ans;
        if(ab[0][i]%ab[1][i]==0)continue;
        ans+=ab[1][i]-(ab[0][i])%ab[1][i];
    }
    cout<<ans<<endl;
    return 0;
}