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
////////////////////////////////////////
ll n,m;

ll calc(ll x,ll y){
    return (m+y-x)%m;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    cin>>n>>m;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll sum=0;
    rep(i,0,n-2){
        sum+=calc(a[i],a[i+1]);
    }
    vector<ll>v[m+1];
    rep(i,0,n-2){
        ll x=a[i],y=a[i+1];
        v[y].pb(calc(x,y)-1);
    }
   /* rep(i,1,m){
        cout<<i<<":";
        if(v[i].size()>=1){
            for(auto x:v[i])cout<<x<<" ";
        }cout<<endl;
    }*/
    ll imos[2*m+1];memset(imos,0,sizeof(imos));
    rep(i,0,n-2){
        ll x=a[i],y=a[i+1];
        if(calc(x,y)>=2){
            imos[x+1]++;
            if(y>=x){
                imos[y]--;
            }else{
                imos[m+y]--;
            }
        }
    }
    
    rep(i,1,2*m)imos[i]=imos[i-1]+imos[i];
    rep(i,1,m){
        imos[i]+=imos[i+m];
    }
    /*  rep(i,1,m){
        cout<<imos[i]<<" ";
    }cout<<endl;
    */
    ll ans=0;
    rep(i,0,n-2){
        if(a[i]<=a[i+1]){
            ans+=calc(a[i],a[i+1]);
        }else{
            ans+=a[i+1];
        }
    }
    ll minans=ans;
   // cout<<1<<" "<<ans<<endl;
    rep(i,2,m){
        if(v[i-1].size()>=1){
            for(auto x:v[i-1]){
                ans+=x;
            }
        }
        ans-=imos[i-1];
       // cout<<i<<" "<<ans<<endl;
        minans=min(minans,ans);
    }
    cout<<minans<<endl;
    
    
    return 0;
}