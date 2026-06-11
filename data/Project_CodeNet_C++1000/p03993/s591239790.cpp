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

int func(int x){
  if(x%100!=0) return 0;
  return func(x/100)+1;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  int ans=0;
  rep(i,n){
    if(i+1==a[a[i]-1]){
      ans++;
    }
  }
  cout<<ans/2<<endl;
}