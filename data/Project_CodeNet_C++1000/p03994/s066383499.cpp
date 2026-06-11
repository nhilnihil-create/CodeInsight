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
  string S; ll K; cin >> S >> K;
  int N = S.size();
  char ans[N];
  rep(i, N-1){
    ll tmp = 26 - (S[i]-'a');
    if(K>=tmp && S[i]!='a'){
      K-=tmp; ans[i] = (S[i] - 'a' + tmp)%26 + 'a';
    }
    else ans[i] = S[i];
  }
  ans[N-1] = (S[N-1] - 'a' + (K%26))%26 + 'a';
  rep(i, N){
    cout << ans[i];
  }
  cout << endl;
}