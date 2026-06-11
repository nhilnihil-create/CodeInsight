#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
vec r(2001,0),d(2001,0),s(2001,0);
vector<int> G[200001];
int z=0;
int search(int x,int y){
    if(x==z||r[x]) return 0;
    r[x]=1;
    d[x]=y;
    for(auto i:G[x]) search(i,y+1);
}
int main(){
    ll n,k,a,b;
    cin>>n>>k;
    rep(i,n-1) cin>>a>>b,G[a].push_back(b),G[b].push_back(a);
    if(k%2==0){
        ll ans=n;
        rep(i,n){
            fill(all(r),0),fill(all(d),0);
            search(i+1,0);
            ll c=0;
            rep(j,n) if(d[j+1]>k/2) c++;
            ans=min(ans,c);
        }
        cout<<ans<<"\n";
    }
    else{
        ll ans=n;
        rep(i,n)for(auto j:G[i+1]){
            z=j;
            fill(all(r),0),fill(all(d),0);
            search(i+1,0);
            z=0;
            search(j,0);
            ll c=0;
            rep(j,n) if(d[j+1]>(k-1)/2) c++;
            ans=min(ans,c);
        }
        cout<<ans<<"\n";
    }
}