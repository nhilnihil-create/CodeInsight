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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll W,H;
P cost[200010];
int main(){
    cin>>W>>H;
    for(ll i=0;i<W;i++){
        ll p;cin>>p;
        cost[i]=P(p,i);
    }
    for(ll i=0;i<H;i++){
        ll q;cin>>q;
        cost[i+W]=P(q,i+W);
    }
    sort(cost,cost+H+W);
    ll wConnectCnt=0;
    ll hConnectCnt=0;
    ll ans=0;
    for(ll i=0;i<H+W;i++){
        ll num=cost[i].second;
        ll c=cost[i].first;
        if(num<W){//取り出したのがp(横方向の道)なら
            wConnectCnt++;
            ans+=c*(H+1-hConnectCnt);
        }else{
            hConnectCnt++;
            ans+=c*(W+1-wConnectCnt);
        }
    }
    cout<<ans;
}