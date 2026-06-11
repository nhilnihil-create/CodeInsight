#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
ll n,m;
ll BIT[200005];
void add(ll x,ll y){
    while(x<=n){
        BIT[x]+=y;
        x+=(x&-x);
    }
}
ll sum(ll x,ll y){
    m=0;
    x--;
    while(y>=1){
        m+=BIT[y];
        y-=(y&(-y));
    }
    while(x>=1){
        m-=BIT[x];
        x-=(x&(-x));
    }
    return m; 
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    memset(BIT,0,sizeof(BIT));
    ll k,a;
    cin>>n>>k;
    vector<pair<ll,ll> > v;
    v.push_back({0,1});
    for(int i=1;i<=n;i++){
    	cin>>a;a-=k;
    	v.push_back({v[i-1].first+a,i+1});
    }
    sort(be(v));
    ll ans=0;
    for(auto& i:v){
    	ans+=sum(1,i.second-1);
    	add(i.second,1);
    }
    cout << ans << endl;
    return 0;
}
