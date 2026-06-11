#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,x;
ll a[2010];
int main(){
    cin>>N>>x;
    for(ll i=0;i<N;i++){
        cin>>a[i];
    }
    multiset<ll> st;
    ll ans=INF;
    for(ll m=0;m<N;m++){
        for(ll i=N-m;i<N;i++){
            st.insert(a[i]);
        }
        ll cnt=0;
        ll deleteIndex=N-m;
        if(m==0)deleteIndex=0;
        for(ll i=0;i<N;i++){
            st.insert(a[i]);
            auto minIt=st.begin();
            cnt+=*minIt;
            st.erase(a[deleteIndex]);
            deleteIndex++;
            if(deleteIndex>=N)deleteIndex=0;
        }
        ans=min(ans,cnt+x*m);
    }
    cout<<ans<<endl;
    return 0;
}