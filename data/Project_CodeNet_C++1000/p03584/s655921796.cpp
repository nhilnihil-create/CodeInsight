#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
#include<cmath>
#include<stack>
#include<tuple>
#include<numeric>
#include<cassert>

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pb push_back
#define DEBUG false

using namespace std;

using ll = long long;
using P = pair<int,int>;

const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll LINF=1LL<<60;
const int MAX_N= 200005;
const ll lmod = 1e9+7;

int N,K;
int a[MAX_N];
ll b[MAX_N];

int main(){
  cin >> N >> K ;
  rep(i,N) scanf("%d%lld",a+i,b+i);
  ll ans = 0;
  rep(i,N){
    if((K|a[i])==K) ans += b[i];
  }
  REP(i,0,31){
    int stand = 1<<i;
    if((stand&K) == 0) continue;
    int arbiturary = (1<<i) - 1; //1でも0でもいいところ
    int temp = (K|arbiturary)^stand;
    ll tempA = 0LL;
    rep(i,N){
      if((temp|a[i]) == temp){
        tempA += b[i];
      }
    }
    ans = max(ans,tempA);
  }
  cout << ans << endl;
  return 0;
}
