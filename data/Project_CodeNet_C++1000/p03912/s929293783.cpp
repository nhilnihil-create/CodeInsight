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

vector<ll>r[100010];
ll rd[100010];
int main(void){
    ll n,m;
    cin>>n>>m;
    vector<ll>x(n);
    map<ll,ll>cnt;
    for(ll i=0;i<n;i++)cin>>x[i],cnt[x[i]]++;
    sort(x.begin(),x.end());
    for(ll i=0;i<n;i++)r[x[i]%m].push_back(x[i]);
    for(auto itr=cnt.begin();itr!=cnt.end();++itr){
        rd[(itr->first)%m]+=(itr->second)/2;
    }
    ll ans = 0;
    for(ll i=0;i<=m/2;i++){
        //cout<<r[i].size()<<" "<<r[m-i].size()<<endl;
        if(i==0)ans+=(ll)r[0].size()/2;
        else{
            if(2*i==m)ans+=(ll)r[i].size()/2;
            else{
                if(r[i].size()==0){
                    ans+=rd[m-i];
                    continue;
                }
                if(r[m-i].size()==0){
                    ans+=rd[i];
                    continue;
                }
                if(r[m-i].size()==r[i].size()){
                    ans+=r[i].size();
                    continue;
                }
                ll ri = r[i].size();
                ll rmi = r[m-i].size();
                ll d1 = rmi-ri;
                ll d2 =ri-rmi;
                if(d1>0){
                    ll p = rd[m-i];
                    if(2*p>=d1)ans+=ri+d1/2;
                    else ans+=ri+p;
                }
                if(d2>0){
                    ll p = rd[i];
                    if(2*p>=d2)ans+=rmi+d2/2;
                    else ans+=rmi+p;
                }
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}