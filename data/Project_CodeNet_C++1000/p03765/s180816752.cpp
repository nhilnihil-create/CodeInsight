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

const int mx=100010;
const ll mod=1e9+7;

int main(){
  string s,t;
  cin >> s >> t;
  vector<int> sa(mx,0),sb(mx,0),ta(mx,0),tb(mx,0);
  int ssz = s.size(), tsz = t.size();
  rep(i,ssz){
    if(s[i]=='A'){sa[i]++;}else{sb[i]++;}
  }
  rep(i,tsz){
    if(t[i]=='A'){ta[i]++;}else{tb[i]++;}
  }

  vector<int> scnt(ssz+1,0);
  rep(i,ssz){
    scnt[i+1] = scnt[i] + sb[i] + sa[i]*2;
  }
  vector<int> tcnt(tsz+1,0);
  rep(i,tsz){
    tcnt[i+1] = tcnt[i] + tb[i] + ta[i]*2;
  }

  int T; cin >> T;
while(T--){
  int a,b,c,d; cin >> a >> b >> c >> d;
  if(((scnt[b]-scnt[a-1])-(tcnt[d]-tcnt[c-1]))%3==0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
  return 0;
}