#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n,k;
ll a[20];
ll ans=1000000000000000000;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int bit=0;bit<(1<<n);bit++){
        int c=0;
        for(int i=0;i<n;i++){
            if((1<<i)&bit) c++;
        }
        if(c>=k){
            ll m=0;
            ll C=0;
            for(int i=0;i<n;i++){
                if((1<<i)&bit){
                    if(m<a[i]){
                        m=a[i];
                    }else{
                        C+=(m-a[i]+1);
                        m++;
                    }
                }else{
                    m=max(m,a[i]);
                }
            }
            ans=min(ans,C);
        }
    }
    cout<<ans<<endl;
    
}
