#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    int n,t;cin>>n>>t;
    vector<int>a(n);
    vector<int>p(n);
    rep(i,n)cin>>a[i];
    int mi=a[0],ma1=0;
    REP(i,1,n){
        mi=min(mi,a[i]);
        p[i]=a[i]-mi;
        ma1=max(ma1,p[i]);
    }
    ll cnt=0;
    rep(i,n)if(p[i]==ma1)cnt++;
    cout<<cnt<<endl;
}