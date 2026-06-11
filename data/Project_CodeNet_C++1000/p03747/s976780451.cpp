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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  LL N, L, T; cin >> N >> L >> T;
  VL xs(N), ds(N);
  vector<bool> cnt(2);
  REP(i,N){
	cin >> xs[i] >> ds[i];
	cnt[ds[i]-1] = true;
  }
  if(!cnt[1]){
	REP(i,N){
	  cout << (xs[i] + T) % L << endl;
	}
	return 0;
  }
  else if(!cnt[0]){
	REP(i,N){
	  cout << (xs[i] - T%L + L) % L << endl;
	}
	return 0;
  }

  LL id = 0;
  if(ds[0] == 1){
	FOR(i,1,N){
	  if(ds[i] == 2 && xs[i]-xs[0] <= 2*T)
		(id += (2*T - (xs[i] - xs[0])) / L + 1) %= N;
	}
  }
  else{
	FOR(i,1,N){
	  if(ds[i] == 1 && xs[0] + L - xs[i] <= 2*T)
		(id += N - (2*T - (xs[0] + L - xs[i])) / L % N + N-1) %= N;
	}
  }

  VL ps(N);
  REP(i,N) ps[i] = (xs[i] + L + T%L * (ds[i]==1?1:-1)) % L;

  LL x0 = ps[0];
  SORT(ps);

  int i0 = lower_bound(ALL(ps), x0) - begin(ps);
  //cout<<x0<<","<<i0<<","<<id<<endl;
  if(i0+1<N&&ps[i0] == ps[i0+1] && ds[0] == 1)
	((--id)+=N)%=N;
  VL ans(N);
  REP(i,N) ans[(i+id)%N] = ps[(i+i0)%N];
  
  for(auto a: ans)
	cout << a << endl;

  return 0;
}
