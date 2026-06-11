#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

int a[100];
signed main(){
  int n,k;cin>>n>>k;
  rep(i,n)cin>>a[i];
  sort(a,a+n,greater<int>());
  int ans=0;
  rep(i,k)ans+=a[i];
  cout<<ans<<endl;
  
  return 0;
}