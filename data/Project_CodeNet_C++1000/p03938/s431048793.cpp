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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1000003 ;
const double pi = 3.141592653589793;

int main(){
  int n;
  cin >> n;
  ll p[n];
  rep(i,n)cin >> p[i];
  ll q[n];
  rep(i,n)q[p[i]-1]=i+1;
  ll a[n]={},b[n]={};
  rep(i,n){
    a[i]=20001*i+q[i];
    b[i]=-20001*i+20001*20001;
  }
  rep(i,n)cout << a[i] << ' ';
  cout << endl;
  rep(i,n)cout << b[i] << ' ';
  cout << endl;
return 0;}