#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define repU(i,s,t) for(int i = (s); i <= (t); ++i)
#define repD(i,t,s) for(int i = (t); i >= (s); --i)
#define all(v)  begin(v),end(v)
#define clr(v) fill(all(v),0)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n - 1)/(d) + 1)
#define parity(a,b) (((a)^(b)) & 1 ^ 1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = -1 + (1 << 30);
const ll INF_64 = -1 + (1LL << 62);
const int MOD = 1e9 + 7;

ull nxt_sbset(ull s){
	ull tem = s + (s & -s);
	ull btm = (~tem & s) / (s & -s) >> 1;
	return btm | tem;
}

int n,a[305][305];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll s = 0;
  bool f;
	cin>>n;
	rep(i,n)rep(j,n){ cin>>a[i][j],s += a[i][j]; }
	s /= 2;
	rep(i,n)repU(j,i + 1,n - 1){
		f = 0;
		rep(k,n){
			if(a[i][j] > a[i][k] + a[k][j]){ cout<<-1<<'\n'; return 0; }
			if(!f && k != i && k != j && a[i][j] == a[i][k] + a[k][j]) s -= a[i][j],f = 1;
		}
	}
	cout<<s<<'\n';
}
