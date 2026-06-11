#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
////////////////////////////////////////////////////////////

signed main() {
  int n;
  cin>>n;
  int four=0,two=0,ki=0;
  rep(i,n){
    int t;cin>>t;
    if(t%4==0)four++;
    else if(t%2==0)two++;
    else ki++;
  }
  if(two+four==n||four>=ki||(two==0&&four>=ki-1))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
