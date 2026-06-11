#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int l,r;
int ans;
int main(void){
    cin>>n;
    while(n--){
        cin>>l>>r;
        ans+=(r-l+1);
    }
    cout<<ans<<endl;
    
}
