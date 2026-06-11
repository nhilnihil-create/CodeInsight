#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

struct BIT{
  int size;
  vector<ll> dat;
  void init(int n){
    size=n;
    dat.clear();
    dat.resize(n+1);
  }
  void add(int i,ll x){
    while(i<=size){
      dat[i]+=x;
      i +=i&-i;
    }
  }
  ll sum(int i){
    ll s=0;
    while(0<i){
      s +=dat[i];
      i -=i&-i;
    }
    return s;
  }
};

pair<int,pint> p[300001];
int main(){
    int n,m,l,r;
    cin>>n>>m;
    BIT b1,b2;
    b1.init(m);
    b2.init(m);
    rep(i,n){
        cin>>l>>r;
        p[i]=mp(r-l+1,mp(l,r));
    }
    sort(p,p+n);
    int x=1,cnt=0;
    FOR(i,1,m+1){
        while(cnt<n&&p[cnt].first<i){
            l=p[cnt].second.first,r=p[cnt].second.second;
            b1.add(l,x);
            b2.add(l,-x*(l-1));
            b1.add(r,-x);
            b2.add(r,x*r);
            ++cnt;
        }
        int ans=n-cnt;
        for(int j=0;j<=m;j+=i) ans+=b1.sum(j)*j+b2.sum(j)-b1.sum(j-1)*(j-1)-b2.sum(j-1); 
        cout<<ans<<endl;
    }
    return 0;
}