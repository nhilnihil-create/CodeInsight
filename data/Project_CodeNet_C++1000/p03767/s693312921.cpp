#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  int n;
  cin>>n;
  vector<int> a(3*n);
  rep(i,3*n) cin>>a[i];
  sort(all(a));
  reverse(all(a));
  ll ans=0;
  for(int i=1;i<2*n;i+=2){
    ans+=a[i];
  }
  cout<<ans<<endl;
}