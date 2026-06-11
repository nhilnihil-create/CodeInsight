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
  int N; cin >> N; int a[N]; int ma = 0, mi = inf;
  if(N==2){
    int a, b; cin >> a >> b;
    if(a!=1 || b!=1){
      cout << "Impossible" << endl;
    }
    else cout << "Possible" << endl;
    return 0;
  }
  rep(i, N){
    cin >> a[i]; ma = max(ma, a[i]); mi = min(mi, a[i]);
  }
  if(ma==1){
    cout << "Impossible" << endl; return 0;
  }
  if(mi!=(ma+1)/2){
    cout << "Impossible" << endl; return 0;
  }
  int cnt[N] = {};
  rep(i, N){
    cnt[a[i]]++;
  }
  if(ma%2==0){
    if(cnt[mi]!=1){
      cout << "Impossible" << endl; return 0;
    }
  }
  else{
    if(cnt[mi]!=2){
      cout << "Impossible" << endl; return 0;
    }
  }
  for(int i=mi+1; i<=ma; i++){
    if(cnt[i]<2){
      cout << "Impossible" << endl; return 0;
    }
  }
  cout << "Possible" << endl; return 0;
}