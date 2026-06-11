#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;


int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m),c(m);
  vector<vector<int>> data(110, vector<int>(110,inf));
  rep(i,n){data[i][i]=0;}
  rep(i,m){ 
    cin >> a[i] >> b[i] >> c[i]; 
    a[i]--; b[i]--; 
    data[a[i]][b[i]]=min(c[i],data[a[i]][b[i]]);
    data[b[i]][a[i]]=min(c[i],data[b[i]][a[i]]);
  }

  rep(i,n)rep(j,n)rep(k,n){
    data[j][k] = min(data[j][k],data[j][i]+data[i][k]);
  }
  
  int ans=m;
  rep(i,m){
    rep(j,n)if(data[j][a[i]]+c[i]==data[j][b[i]]){
      ans--;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}
