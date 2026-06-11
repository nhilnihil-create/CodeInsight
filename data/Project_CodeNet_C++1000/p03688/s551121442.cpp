#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
ll n,a[N],mx=0,mn=N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if(mx>mn+1)return cout<<"No" , 0;

    if(mx==mn){
        if(mn==n-1 || mn*2<=n)cout<<"Yes";
        else cout<<"No";
    }
    else{
        ll cnt=0;for(ll i=0;i<n;i++)cnt+=(a[i]==mn);
        if(cnt<mx && 2*(mx-cnt)<=n-cnt)cout<<"Yes";
        else cout<<"No";
    }
}