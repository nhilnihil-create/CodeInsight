#include<iostream>
#include <cstring>
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
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int N, K; cin >> N >> K; ll a[N]; ll plus=0, minus=0;
  rep(i, N){
    cin >> a[i];
    if(a[i]>0) plus+=a[i];
    if(a[i]<0) minus+=a[i];
  }
  ll sum = plus+minus;
  ll suma=0, sumb=0;
  rep(i, K){
    if(a[i]<0) suma+=a[i];
    if(a[i]>0) sumb+=a[i];
  }
  ll tmpa=-longinf, tmpb=longinf;
  rep(i, N-K){
    tmpa = max(tmpa, suma);
    tmpb = min(tmpb, sumb);
    if(a[i]<0) suma-=a[i];
    if(a[i]>0) sumb-=a[i];
    if(a[i+K]<0) suma+=a[i+K];
    if(a[i+K]>0) sumb+=a[i+K];
  }
  tmpa = max(tmpa, suma);
  tmpb = min(tmpb, sumb);
  cout << max(plus+tmpa, sum-(minus+tmpb)) << endl;
}
  