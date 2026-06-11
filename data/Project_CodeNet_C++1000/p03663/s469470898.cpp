#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

bool input(){
  char c;
  cin >> c;
  return c == 'Y';
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int d = -1;
  string s = "1";
  for(int i=0;i<=10;++i){
	cout << "? " << s << endl;
	if(!input()){
	  d = i;
	  break;
	}
	s += "0";
  }
  if(d < 0){
	s = "9";
	for(int i=1;i<=10;++i){
	  cout << "? " << s << endl;
	  if(input()){
		d = i;
		break;
	  }
	  s += "9";
	}
  }
  if(d == 10){
	cout << "! 1000000000" << endl;
	return 0;
  }

  string ans;
  for(int i=0;i<d-1;++i){
	int lb = 0, ub = 10;
	while(ub-lb > 1){
	  int m = (lb + ub) / 2;
	  string q = ans + string(1, '0'+m);
	  cout << "? " << q << endl;
	  if(input()){
		lb = m;
	  }
	  else{
		ub = m;
	  }
	}
	ans += string(1, '0'+lb);
  }
  {
	int lb = -1, ub = 9;
	while(ub-lb > 1){
	  int m = (lb + ub) / 2;
	  string q = ans + string(1, '0'+m);
	  cout << "? " << q + "0" << endl;
	  if(!input()){
		lb = m;
	  }
	  else{
		ub = m;
	  }
	  if(d == 1 && ub == 1) break;
	}
	ans += string(1, '0'+ub);
  }
  cout << "! " << ans << endl;

  return 0;
}
