#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<ll> a(3*n+1),x(2*n+1),y(2*n+10);
  priority_queue<ll,vector<ll>,greater<ll>> cnt1;
  priority_queue<ll> cnt2;
  ll sum1=0,sum2=0,ans=-inf;
  FOR(i,1,3*n+1){
    cin>>a[i];
    if(i<=n){
      cnt1.push(a[i]);
      sum1+=a[i];
    }else if(2*n+1<=i){
      cnt2.push(a[i]);
      sum2+=a[i];
    }
  }
  x[n]=sum1,y[2*n+1]=sum2;
  FOR(i,n+1,2*n+1){
    cnt1.push(a[i]);
    sum1+=a[i]-cnt1.top();
    cnt1.pop();
    x[i]=sum1;
  }
  for(int i=2*n;i>=n+1;i--){
    cnt2.push(a[i]);
    sum2+=a[i]-cnt2.top();
    cnt2.pop();
    y[i]=sum2;
  }
  FOR(i,n,2*n+1) ans=max(ans,x[i]-y[i+1]);
  cout<<ans<<endl;
}