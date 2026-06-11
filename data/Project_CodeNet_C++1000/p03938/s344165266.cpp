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
const ll MOD=998244353;

int main(){
  int N; cin >> N; int p[N];
  rep(i, N){
    cin >> p[i]; p[i]--;
  }
  vector<ll> a(N), b(N);
  rep(i, N-1){
    if(p[i+1]>p[i]){
      a[p[i+1]] = a[p[i]]+2*(p[i+1]-p[i])*10000;
      b[p[i+1]] = b[p[i]]-2*(p[i+1]-p[i])*10000+1;
    }
    else{
      a[p[i+1]] = a[p[i]]-2*(p[i]-p[i+1])*10000+1;
      b[p[i+1]] = b[p[i]]+2*(p[i]-p[i+1])*10000;
    }
  }
  int t = a[0];
  rep(i,N){
    a[i]+=(1-t);
  }
  t = b[N-1];
  rep(i, N){
    b[i]+=(1-t);
  }
  rep(i, N){
    cout << a[i]; cout << " ";
  }
  cout << endl;
  rep(i, N){
    cout << b[i]; cout << " ";
  }
  cout << endl;
}