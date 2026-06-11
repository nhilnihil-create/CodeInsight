#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  VI xs(N);
  REP(i,N) cin >> xs[i];
  SORT(xs);

  VI s(M), d(M);
  int prv = 0, c = 0;
  REP(i,N){
	if(xs[i] == prv) ++c;
	else{
	  s[prv%M] += c/2;
	  d[prv%M] += c%2;
	  prv = xs[i];
	  c = 1;
	}
  }
  if(c){
	s[prv%M] += c/2;
	d[prv%M] += c%2;
  }

  //REP(i,M) cout << i<<": "<<s[i] << "," << d[i] << endl;
  
  LL ans = 0;
  for(int i=1;i<(M+1)/2;++i){
	int ii = i;
	int j = M - i;
	int si = s[ii]*2 + d[ii];
	int sj = s[j]*2 + d[j];
	if(si < sj){
	  swap(si, sj);
	  swap(ii,j);
	}
	int m = min(si, sj);
	ans += m;
	ans += (s[ii] * 2 - max(0, m - d[ii])) / 2;

	//cout << j << " - " << ii << " -> " << m << " , " << (s[ii] * 2 +d[ii] - m) / 2 << endl;
  }

  ans += (s[0]*2 + d[0]) / 2;
  if(M%2 == 0)
	ans += (s[M/2]*2 + d[M/2]) / 2;

  cout << ans << endl;
  
  return 0;
}
