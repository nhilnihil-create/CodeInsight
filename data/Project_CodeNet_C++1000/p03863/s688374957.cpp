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
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> v[26];

int main(){
  string s;
  cin >> s;
  int n=s.size();
  if(n%2){
    if(s[0]==s[n-1])cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
  }else{
    if(s[0]==s[n-1])cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
  }
  cout << "Second" << endl;
return 0;}