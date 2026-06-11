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
  int N; cin >> N; ll a[N+1]; ll sum = 0;
  rep(i, N){
    cin >> a[i]; sum+=a[i];
  }
  a[N] = a[0];
  ll K = (ll)N*(N+1)/2;
  if(sum%K){
    cout << "NO" << endl; return 0;
  }
  K = sum/K;
  ll sa[N];
  rep(i, N){
    sa[i] = a[i+1] - a[i];
  }
  ll cnt = 0;
  rep(i, N){
    if(-(N-1)*K>sa[i] || sa[i]>K){
      cout << "NO" << endl; return 0;
    }
    if((K-sa[i])%N){
      cout << "NO" << endl; return 0;
    }
    cnt+=((K-sa[i])/N);
  }
  if(cnt!=K){
    cout << "NO" << endl; return 0;
  }
  cout << "YES" << endl;
}