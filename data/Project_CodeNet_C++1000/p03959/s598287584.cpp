#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n;
ll t[100005],a[100005];
ll ans=1;
ll h[100005],u[100005];
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    t[n+1]=0; a[n+1]=0;
    for(int i=1;i<=n;i++){
        if(t[i]>t[i-1]){
            h[i]=t[i];
        }else{
            u[i]=t[i];
        }
    }
    for(int i=n;i>0;i--){
        if(a[i]>a[i+1]){
            if(h[i]==0||h[i]==a[i]){
                if(t[i]<a[i]){
                    cout<<0<<endl;
                    return 0;
                }
                h[i]=a[i];
                u[i]=0;
            }else{
                cout<<0<<endl;
                return 0;
            }
        }else{
            if(h[i]>0){
                if(a[i]<h[i]){
                    cout<<0<<endl;
                    return 0;
                }
            }else{
                u[i]=min(u[i],a[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(h[i]>0){

        }else{
            ans=(ans*u[i])%MOD;
        }
    }
    cout<<ans<<endl;

}

