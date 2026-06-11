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

void yes(){cout<<"Yes"<<endl;}
void no(){cout<<"No"<<endl;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  int ma=*max_element(begin(a),end(a)),mi=*min_element(begin(a),end(a));
  if(ma-mi>1) no();
  else if(ma-mi==1){
    int x=0;
    rep(i,n) if(a[i]==mi) x++;
    if(2*ma<=n+x && x<ma) yes();
    else no();
  }else{
    if(ma==n-1 || 2*ma<=n) yes();
    else no();
  }
}