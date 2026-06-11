#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a[105],sum,ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n>=(n+1)/2){
        sum=sum/n+1;
    }else{
        sum=sum/n;
    }
    for(int i=0;i<n;i++){
        ans+=((a[i]-sum)*(a[i]-sum));
    }
    cout<<ans<<endl;

}
