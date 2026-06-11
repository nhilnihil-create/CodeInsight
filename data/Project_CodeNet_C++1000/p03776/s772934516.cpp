#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 64;
ll com[MAX][MAX];
void COMinit() {
  for(int i=0;i<MAX;i++){
    com[i][0]=1;
    com[i][i]=1;
  }
  for(int i=1;i<MAX;i++){
    for(int j=0;j<=i;j++){
      com[i][j]=com[i-1][j-1]+com[i-1][j];
    }
  }
}
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return com[n][k];
}
int main(){
  COMinit();
  int n,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  for(int i=0;i<n;i++) cin >> x[i];
  sort(x.rbegin(),x.rend());
  double ave=0;
  ll num=0;
  for(int i=0;i<a;i++) ave+=double(x[i]);
  ave/=a;
  int l=100,r=0;
  for(int i=0;i<n;i++){
    if(x[i]==x[a-1]){
      l=min(l,i);
      r=max(r,i);
    }
  }
  int m=r-l+1;
  if(r == a-1) num=1;
  else if(l == 0){
    for(int i=a;i<=b;i++){
      num+=COM(m,i);
    }
  }
  else{
    num+=COM(m,a-l);
  }
  cout << fixed << setprecision(8) << ave << endl << num << endl;
}