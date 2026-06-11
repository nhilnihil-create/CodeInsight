//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll n,arr[200005];  
ll cnt;
vector<pair<ll,int> > v;
ll f(int idx){
    pii x={arr[idx],1};
    while(v.empty()==false && v.back().fi > x.fi ){
        x.se+=v.back().se;
        cnt-=(v.back().fi * v.back().se);
        v.pop_back();
    }
    v.pb(x);
    cnt+=(v.back().fi * v.back().se);
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];

    }
    for(int i=n;i>=1;i--){
        ans+=f(i);
    }
    cout<<ans<<endl;
}