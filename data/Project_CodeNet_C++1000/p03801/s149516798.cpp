#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    vector<i_i>v;
    v.pb(i_i(0,-1));
    ll max=0;
    rep(i,0,n-1){
        if(max<a[i]){
            max=a[i];
            v.pb(i_i(a[i],i));
        }
    }
    ll ans[n];memset(ans,0,sizeof(ans));
    sort(a,a+n);
    ll t=n-1,vlen=v.size();
    for(int vpos=vlen-1;vpos>=1;vpos--){
        ans[v[vpos].second]=(n-t-1)*(v[vpos].first-v[vpos-1].first);
        while(t>=0){
            if(a[t]<v[vpos-1].first)break;
            ans[v[vpos].second]+=(a[t]-v[vpos-1].first);
            t--;
        }
    }
    /*rep(i,0,n-1){
        ans[v[0].second]+=min(v[0].first,a[i]);
    }*/
    rep(i,0,n-1){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}