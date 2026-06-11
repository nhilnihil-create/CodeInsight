//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll w,h,ans=0; cin>>w>>h;
    vector<pair<ll,ll>> e(w+h,mk(0,0));
    rep(i,w){
        ll p; cin>>p;
        e[i]=mk(p,0);
    }
    rep(i,h){
        ll q; cin>>q;
        e[w+i]=mk(q,1);
    }
    sort(al(e));
    ll wcnt=w+1,hcnt=h+1;
    rep(i,w+h){
        if(e[i].second){
            ans+=wcnt*e[i].first;
            hcnt--;
        }
        else{
            ans+=hcnt*e[i].first;
            wcnt--;
        }
    }
    cout<<ans<<endl;
}
