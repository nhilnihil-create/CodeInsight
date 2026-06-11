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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N; cin >> N; int a[N]; int cnt[101010] = {};
  rep(i, N){
    cin >> a[i]; a[i]--; cnt[a[i]]++;
  }
  int gusu = 0, ans = 0;
  rep(i, 101010){
    if(cnt[i]==0) continue;
    ans++;
    if(cnt[i]%2==0) gusu++;
  }
  if(gusu!=0 && gusu%2) ans--;
  cout << ans << endl;
}