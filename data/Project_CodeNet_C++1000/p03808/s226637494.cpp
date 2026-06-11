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
  ll n,k;
  ll sum=0;
  cin>>n;
  vector<ll> a(n+1),d(n+1);
  FOR(i,1,n+1){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%(n*(n+1)/2)!=0){
    cout<<"NO"<<endl;
    return 0;
  }else k=sum/(n*(n+1)/2);
  FOR(i,1,n) d[i]=a[i+1]-a[i]-k;
  d[n]=a[1]-a[n]-k;
  int ans=0;
  FOR(i,1,n+1){
    if(d[i]<0) d[i]*=-1;
    if(d[i]%n!=0){
      cout<<"NO"<<endl;
      return 0;
    }else ans+=d[i]/n;
  }
  if(ans==k) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}