#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
const int MAX_N=200001;
int bit[MAX_N+1]={0},n;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n+1){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main(){
    int k;
    cin>>n>>k;
    ll ans=0;
    vec A(n),B(n+1,0);
    rep(i,n) cin>>A[i],A[i]-=k,B[i+1]=B[i]+A[i];
    vector<P> C;
    rep(i,n+1) C.push_back(P(B[i],i));
    sort(all(C));
    int a=1;
    rep(i,n+1){
        if(i&&C[i-1].first!=C[i].first) a++;
        B[C[i].second]=a;
    }
    for(int i=n;i>=0;i--){
        ans+=sum(n+1)-sum(B[i]-1);
        add(B[i],1);
    }
    cout<<ans<<"\n";
}