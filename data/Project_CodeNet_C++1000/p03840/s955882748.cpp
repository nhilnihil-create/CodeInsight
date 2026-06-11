#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

int main(){
    ll I,O,T,J,L,S,Z;
    cin>>I>>O>>T>>J>>L>>S>>Z;
    ll ans=O;
    if( (I%2==1?1:0)+(J%2==1?1:0)+(L%2==1?1:0)>=2 && I*J*L!=0 ){
        I--;
        J--;
        L--;
        ans+=3;
    }
    ans+=I/2*2+J/2*2+L/2*2;
    cout<<ans<<endl;
    return 0;
}