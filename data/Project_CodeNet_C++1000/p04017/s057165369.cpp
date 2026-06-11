#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os << "[ "; 
	for(auto v:V)os << v << " "; return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){ os << "{ "; 
	for(auto s:S) os<<s<<" ";  return os<<"}"; 
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os<<"("<<P.first<<","<< P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
	os<<"{ ";for(auto m:M)os<<"("<<m.F<<":"<<m.S<<")";
	return os<<"}";
}
#define cerr cout
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(int i=0;i<(int)n;++i)
#define Rev(i,n) for(int i=(int)n-1;i>=0;--i)
#define Rep(i,n) for(int i=1;i<=(int)n;++i)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpii;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e5 + 100;
const int LN = 20;
int MX[LN][N];
int pre[N];
int X[N];


int main(){
	fio; cout<<fixed<<setprecision(25);	
	int n; cin >> n;

	for(int i =1 ;i <= n ; ++i)
		cin >> X[i];

	int l , q; cin >> l >> q;

	MX[0][n] = n;
	int i = n-1, j = n;
	while(i >= 1){
		while(j > i && X[j]-X[i] > l){
			--j;
		}
		MX[0][i] = j;
		// trace(MX[0][i]);

		--i;
	}
	
	for(int i =1 ;i < LN ; ++i){
		for(int j = 1;j <= n ; ++j){
			MX[i][j] = MX[i-1][MX[i-1][j]];
		}
	}

	while(q--){
		int u , v;
		cin >> u >> v;
		if(u > v) swap(u , v);
		int ans = 0;
		// trace(u , v);
		for(int i = LN-1;i >= 0 ; --i){
			// trace(MX[i][u]);
			if(MX[i][u] < v){
				ans += (1<<i);
				u = MX[i][u];
			}
		}
		++ans;
		cout << ans << endl;
	}







	return 0;
}












