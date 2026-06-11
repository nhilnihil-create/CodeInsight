#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() { 
 int n,m,k;
  cin>>n>>m>>k;
  ////////nを固定して全探索
  bool ok=false;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      int b=i*j+(n-i)*(m-j);
      if(b==k) ok=true;
    }
    if(ok) break;
    
    
  }
  if(ok)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}