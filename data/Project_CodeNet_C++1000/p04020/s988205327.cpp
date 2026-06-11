#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[100005];
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0&&a[i]>0){
            ans+=(a[i]/2-1);
            a[i]=2;
            if(i==0||a[i-1]==0){
                a[i]=0;
                ans++;
            }
        }else if(a[i]>0){
            ans+=a[i]/2;
            a[i]=1;
        }
    }
    for(int i=0;i<n-1;i++){
        if(a[i]==0&&a[i+1]==2){
            ans++;
            a[i]=0;
            a[i+1]=0;
        }else if(a[i]+a[i+1]>=2){
            ans++;
            a[i]--;
            a[i+1]--;
        }
    }
    cout<<ans<<endl;
    

}

