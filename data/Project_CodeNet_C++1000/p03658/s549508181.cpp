#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k;
int l[55];
ll ans;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>l[i];
        ans+=l[i];
    }
    sort(l,l+n);
    for(int i=0;i<n-k;i++){
        ans-=l[i];
    }
    cout<<ans<<endl;
    
}
