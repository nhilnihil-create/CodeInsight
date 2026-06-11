#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  rep(i,0,n) cin>>a[i];
  sort(a,a+n,greater<>());
  int ans=0;
  rep(i,0,k) ans+=a[i];
  cout<<ans<<endl;
}