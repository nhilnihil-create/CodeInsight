#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll w,h,p,num[2],ans;
vector<pair<ll,bool>>vec;

int main(){
    cin>>w>>h;
    num[0]=h+1;
    num[1]=w+1;
    rep(i,w+h){
        cin>>p;
        vec.push_back({p,i<w});
    }
    sort(vec.begin(),vec.end());
    rep(i,w+h){
        ll cost=vec[i].first;
        bool b=vec[i].second;
        ans+=num[!b]*cost;
        num[b]--;
    }
    cout<<ans<<endl;
}