#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    vector<ll>a(n+1),b(n+1),c(n+1),p(n+1);
    c[0]=1;
    REP(i,1,n+1){
        c[i]=c[i-1]+1;
    }
    rep(i,n){
        ll d;cin>>d;
        p[d]=i+1;
    }
    a[1]=1;
    b[1]=p[1]-a[1];
    ll mi=b[1];
    REP(i,2,n+1){
        if(p[i]<p[i-1]){
            a[i]=a[i-1]+1;
            b[i]=p[i]-a[i];
        }else{
            b[i]=b[i-1]-1;
            a[i]=p[i]-b[i];
        }
        mi=min(b[i],mi);
    }
    REP(i,1,n+1)b[i]+=abs(mi)+1;
    REP(i,1,n+1)cout<<a[i]<<' ';
    cout<<endl;
    REP(i,1,n+1)cout<<b[i]<<' ';
}