#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll k,s;
ll ans;
int main(void){
    cin>>k>>s;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            if(0<=s-x-y&&s-x-y<=k){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    
}
