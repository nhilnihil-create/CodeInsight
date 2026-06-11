#include <bits/stdc++.h>
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
 
const int mx=200010;
const ll mod=1e9+7;


int main(){  
  int h,w;
  cin >> h >> w;
  if(h%3==0||w%3==0){ cout << 0 <<endl; return 0; }
  ll ans=min(h,w);
  rep(i,2){
  int w1 = w*2/3;
  int w2 = w*2/3+1;
  ll tmp[2][3];
  tmp[0][0] = h*(w-w1);
  tmp[0][1] = (h/2+h%2)*w1;
  tmp[0][2] = (h/2)*w1;
  tmp[1][0] = h*(w-w2);
  tmp[1][1] = (h/2+h%2)*w2;
  tmp[1][2] = (h/2)*w2;
  sort(tmp[0],tmp[0]+3);
  sort(tmp[1],tmp[1]+3);
  ans = min(ans,abs(tmp[0][0]-tmp[0][2]));
  ans = min(ans,abs(tmp[1][0]-tmp[1][2]));
  swap(h,w);
  }
  cout << ans << endl;
  return 0;
}