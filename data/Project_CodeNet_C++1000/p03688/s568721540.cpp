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
  int N; cin >> N; int a[N]; int mi = inf, ma = 0;
  rep(i, N){
    cin >> a[i]; mi = min(a[i], mi); ma = max(a[i], ma);
  }
  if(ma-mi>1){
    cout << "No" << endl; return 0;
  }
  if(ma==mi){
    if(ma==N-1){
      cout << "Yes" << endl; return 0;
    }
    if(N>=ma*2){
      cout << "Yes" << endl; return 0;
    }
    cout << "No" << endl; return 0;
  }
  int micnt=0, macnt=0;
  rep(i, N){
    if(a[i]==mi) micnt++; else macnt++;
  }
  if(micnt + macnt/2 >=ma && micnt + 1<=ma){
    cout << "Yes" << endl; return 0;
  }
  cout << "No" << endl;
}
