#include<bits/stdc++.h>
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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
const double EPS=1E-8;
////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll w,h;cin>>w>>h;
    ll a[w];rep(i,0,w-1)cin>>a[i];
    ll b[h];rep(i,0,h-1)cin>>b[i];
    
    int aa=h,bb=w;
    priority_queue<l_l,vector<l_l>,greater<l_l>>q;
    rep(i,0,w-1)q.push(l_l(a[i],1));
    rep(i,0,h-1)q.push(l_l(b[i],2));
    ll res=w*h;
    ll ans=0;rep(i,0,w-1)ans+=a[i];rep(i,0,h-1)ans+=b[i];
    while(res>0){
        l_l t=q.top();q.pop();
        if(t.second==1){
            if(res-aa>=0){
                res-=aa;
                ans+=t.first*aa;
                bb--;
            }else{
                ans+=t.first*res;
                res=0;
            }
        }else{
            if(res-bb>=0){
                res-=bb;
                ans+=t.first*bb;
                aa--;
            }else{
                ans+=t.first*res;
                res=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}