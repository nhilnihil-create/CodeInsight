#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

struct BIT{
private:
    vector<ll> a;
    int n;
public:
    BIT(int sz){
        n=sz;
        a.resize(sz+1);
    }
    ll sum(int i){
        ll res=0;
        while(i>0){
            res+=a[i];
            i-=i&-i;
        }
        return res;
    }
    ll sum(int i,int j){
        return sum(j)-sum(i-1);
    }
    void add(int i,ll x){
        while(i<=n){
            a[i]+=x;
            i+=i&-i;
        }
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    ll a[n+1];
    a[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>a[i];
        a[i]-=k;
        a[i]+=a[i-1];
    }
    pair<ll,int> p[n+1];
    for(int i=0;i<n+1;i++){
        p[i]={a[i],i};
    }
    sort(p,p+n+1);
    for(int i=0;i<n+1;i++){
        a[p[i].second]=i+1;
    }
    ll ans=0;
    BIT bit(n+1);
    for(int i=0;i<n+1;i++){
        ans+=bit.sum(a[i]);
        bit.add(a[i],1);
    }
    cout<<ans<<endl;
}