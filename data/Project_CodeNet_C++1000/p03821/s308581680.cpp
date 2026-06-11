#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        if((a[i]+ans)%b[i]==0) continue;
        ans+=b[i]-(a[i]+ans)%b[i];
    }
    cout<<ans<<endl;
}