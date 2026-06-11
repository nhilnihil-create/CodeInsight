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
#include<memory.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n,x;
  cin >> n >> x;
  if(x<2 || x>2*n-2){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<int> v;
  rep(i,2*n-1){
    if(i+1!=x)v.push_back(i+1);
  }
  rep(i,n-1){
    cout << v[n-2-i] << ' ';
  }
  cout << x << ' ';
  rep(i,n-1){
    cout << v[2*n-3-i] << ' ';
  }
  cout << endl;
return 0;}