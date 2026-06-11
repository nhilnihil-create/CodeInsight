#include <bits/stdc++.h>
const int N=100005;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n;
vector<ll>ans(N,0);
vector<pii>ar;
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;ar.push_back({x,-i});
    }
    sort(ar.begin(),ar.end());
    reverse(ar.begin(),ar.end());
    ll mn=-ar[0].second;
    ll pr=ar[0].first;
    ll cnt=0;
    for(auto el:ar){
        auto vl=el.first;
        auto p=-el.second;
        if(pr!=vl){
            //cout<<mn<<' '<<vl<<' '<<pr<<' '<<cnt<<' '<<ans[mn]<<'\n';
            ans[mn]+=(pr-vl)*cnt;
            pr=vl;
        }
        cnt++;
        mn=min(mn,p);


    }
    ans[1]+=pr*n;
    for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
    return 0;
}
