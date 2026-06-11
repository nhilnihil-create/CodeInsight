#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k,x[105];
int ans;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i];
        ans+=(min(abs(x[i]),abs(k-x[i]))*2);
    }
    cout<<ans<<endl;
    
}
