#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n)cin >> v[i];
  int L,Q;
  cin >> L >> Q;
  vector<vector<int>> next(n,vector<int>(20,n-1));
  rep(i,n){
    auto iter = lower_bound(ALL(v),v[i]+L);
    if(iter == v.end())continue;
    if(*iter <= v[i]+L)next[i][0] = iter-v.begin();
    else next[i][0] = iter-v.begin()-1;
  }
  rep(j,19)rep(i,n)next[i][j+1] = next[next[i][j]][j];
  while(Q--){
    int a,b;cin >> a >> b;
    a--,b--;
    if(a > b)swap(a,b);
    int l = 0,r = 100100;
    while(r-l > 1){
      int mid = (r+l)/2;
      int pos = a;
      for(int i = 19;i >= 0;i--)if(mid >> i & 1)pos = next[pos][i];
      if(pos >= b)r = mid;
      else l = mid;
    }
    cout << r << endl;
  }







  return 0;
}