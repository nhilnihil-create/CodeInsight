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

ll X[2][N];
ll ans[10];

int main(){
	fio; cout<<fixed<<setprecision(25);	
	
	ll h , w , n;
	cin >> h >> w >> n;

	for(int i = 1; i <= n ; ++i){
		cin >> X[0][i] >> X[1][i];
	}
	map<pii , int> s;
	for(int i =1 ;i<= n ; ++i){
		for(int j = -2; j <= 0 ; ++j){
			for(int k = -2 ; k <= 0 ; ++k){
				int x = X[0][i]+j , y = X[1][i]+k;
				if(x >= 1 && y >= 1 && x+2 <= h && y+2 <= w)
					s[mp(x , y)]++; 
			}
		}

	}
	ll tot = (h-2)*(w-2);
	
	for(auto it : s){
		ans[it.S]++;
	}
	cout << tot-s.size() << endl;
	for(int i =1 ;i <= 9 ; ++i){
		cout << ans[i] << endl;
	}



	return 0;
}
