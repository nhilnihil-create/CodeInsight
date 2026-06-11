#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,k,ans,a[N],b[N];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if((a[i]&k)==a[i])ans+=b[i];
    }
    for(ll i=1;i<=(1ll<<30);i<<=1){
        if(!(k&i))continue;
        ll sum=0,t=(k^i)|(i-1);
        for(ll j=0;j<n;j++)if((a[j]&t)==a[j])sum+=b[j];
        ans=max(ans,sum);
    }
    cout<<ans;
}