#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  map<ll,int> m;
  vector<ll> v;
  rep(i,0,n){
    ll a;
    cin>>a;
    if(m[a]==0) m[a]++;
    else{
      v.push_back(a);
      m[a]=0;
    }
  }
  sort(v.rbegin(),v.rend());
  if(v.size()<2){
    cout<<0<<endl;
  }
  else{
    cout<<v[0]*v[1]<<endl;
  }
}