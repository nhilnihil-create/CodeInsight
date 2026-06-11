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
 
const int mx=200010;
const ll mod=1e9+7;


int main(){  
  int h,w,n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<vector<int>> data(h, vector<int>(w));
  int cnt=0;
  rep(i,h)rep(j,w){
      data[i][(i%2==0?j:w-1-j)] = cnt+1;
      a[cnt]--;
      if(a[cnt]==0){ cnt++; }
  }
  rep(i,h) {rep(j,w){
    cout << data[i][j] << " ";
  } cout << endl;
  }
  return 0;
}