#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n,m;
  cin >> n >> m;
  int a[n][m];
  rep(i,n){
    rep(j,m){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  int ans[m]={};
  int step[n]={};
  set<int> se;
  rep(i,m){
    int cnt[m]={};
    rep(j,n){
      cnt[a[j][step[j]]]++;
    }
    int M=-1;
    rep(j,m)M=max(M,cnt[j]);
    rep(j,m){
      if(cnt[j]==M){
        ans[j]=M;
        se.insert(j);
        break;
      }
    }
    rep(i,n){
      while(se.find(a[i][step[i]])!=se.end())step[i]++;
    }
  }
  int an=inf;
  rep(i,m)an=min(an,ans[i]);
  cout << an << endl;
return 0;}