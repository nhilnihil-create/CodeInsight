#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll>Q;

ll ans[200010];

int main(void){
    ll n;
    cin>>n;
    map<ll,ll>cnt,index;
    priority_queue<ll,vector<ll>,less<ll> >pq;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        if(index[a]==0){
            cnt[a]++;
            index[a]=i+1;
            pq.push(a);
        }
        else cnt[a]++;
    }
    if(pq.size()==1){
        ll t = pq.top();
        for(int i=1;i<=n;i++){
            if(i==1)cout<<t*n<<endl;
            else cout<<0<<endl;
        }
        return 0;
    }
    while(!pq.empty()){
        if(pq.size()==1){
            ll p = pq.top();
            ans[index[p]]+=p*cnt[p];
            break;
        }
        ll f = pq.top();
        pq.pop();
        ll s = pq.top();
        pq.pop();
        ll d = f-s;
        //cout<<index[f]<<" "<<cnt[f]<<endl;
        ans[index[f]]+=d*cnt[f];
        cnt[s]+=cnt[f];
        if(index[s]>index[f])index[s]=index[f];
        pq.push(s);
    }
    for(ll i=1;i<=n;i++)cout<<ans[i]<<endl;
    return 0;
}