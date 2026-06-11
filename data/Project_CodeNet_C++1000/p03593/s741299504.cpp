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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=1000010;
const ll mod=1e9+7;

int main(){
  int h,w;
  cin >> h >> w;
  int a = (h%2)*(w%2); 
  int b = (h%2)*(w/2) + (w%2)*(h/2);
  int c = (w/2)*(h/2);
  map<char,int> mp;
  rep(i,h*w){
    char c;
    cin >> c;
    mp[c]++;
  }
  for(auto& it:mp){
    while(it.S>0){
      if(it.S%4 == 1 || it.S%4 == 3){
        it.S--;
        a--;
      } else if(it.S%4 == 2 || (it.S%4 == 0 && c==0)) {
        it.S -= 2;
        b--;
      } else if(it.S%4 == 0 && c>0){
        it.S -= 4;
        c--;
      }
    }
  }
  if(a==0 && b==0 && c==0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}