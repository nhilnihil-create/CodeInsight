#include <iostream>
#include <bitset>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll a[n];

    for (int i=0;i<n;i++) cin>>a[i];
    
    ll ans=1e18;
    for (ll bit=0;bit<(1<<n);bit++){
        ll max_h=a[0];
        ll sum=0;
        ll cnt=1;
        for (int i=1;i<n;i++){
            if (bit&(1<<i)){
                if(a[i]<=max_h){
                    sum+=max_h-a[i]+1;
                    cnt++;
                    max_h++;
                }else max_h=a[i];
            }else if(a[i]>max_h){
                cnt++;
                max_h=max(max_h,a[i]);
            }           
        }
        if (cnt>=k) ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}