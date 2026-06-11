#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF=1001001001001001001;


int main() {
  ll n;
  cin>>n;
  vector<ll>a(3*n+5);
  rep(i,n*3)cin>>a[i];
  ll bef=0;
  ll las=0;
  priority_queue<ll, vector<ll>,greater<ll>>qb;
  priority_queue<ll>ql;
  rep(i,n){
    qb.push(a[i]);
    ql.push(a[i+2*n]);
    bef+=a[i];
    las+=a[i+2*n];

  }
vector<ll>B(n+1);
vector<ll>L(n+1);
B[0]=bef;
L[n]=las;
  rep(i,n){
    qb.push(a[n+i]);
    bef+=a[n+i];
    ll now=qb.top();
    bef-=now;
    qb.pop();
    B[i+1]=bef;
  //  cout<<bef<<endl;
  }
  rep(i,n){
    ql.push(a[2*n-1-i]);
    las+=a[2*n-1-i];
    ll now=ql.top();
    las-=now;
    ql.pop();
    L[n-1-i]=las;
  //  cout<<las<<endl;

  }
  ll ans=-INF;
  rep(i,n+1){
    ans=max(ans,B[i]-L[i]);
  //  cout<<ans<<endl;
  }
cout<<ans;

}
