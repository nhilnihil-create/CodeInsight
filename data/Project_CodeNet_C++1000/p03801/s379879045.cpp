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

ll N;
ll a[100010];
ll preIndex[100010];
ll ans[100010];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>a[i];
    }
    ll now=0;
    for(ll i=0;i<N;i++){
        if(a[now]<a[i]){
            preIndex[i]=now;
            now=i;
        }
    }
    multiset<ll> st;
    ll cnt=0;
    for(ll i=now;i<N;i++){
        if(a[i]==a[now])cnt++;
        else st.insert(a[i]);
    }
    while(now>0){
        ll nowAns=cnt*(a[now]-a[preIndex[now]]);
        for(ll i=preIndex[now];i<now;i++){
            st.insert(a[i]);
        }
        vector<multiset<ll>::iterator> remove;
        for(auto it=st.lower_bound(a[preIndex[now]]);it!=st.end();it++){
            nowAns+=(*it)-a[preIndex[now]];
            remove.push_back(it);
        }
        cnt+=remove.size();
        for(auto it:remove){
            st.erase(it);
        }
        ans[now]=nowAns;
        now=preIndex[now];
    }
    ans[0]=cnt*a[0];
    for(auto it=st.begin();it!=st.end();it++){
        ans[0]+=*it;
    }
    for(ll i=0;i<N;i++){
        cout<<ans[i]<<endl;
    }



    return 0;
}