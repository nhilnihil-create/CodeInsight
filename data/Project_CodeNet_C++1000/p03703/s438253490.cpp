#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pii pair<int, int>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

const ll Mod = 1e9 + 7;
const int N = 2e5 + 7;
ll A[N] , table[N] ;

void upt(int x , ll val){
	while(x < N){
		table[x] += val;
		x += x&-x;
	}
}

ll query(int x){
	ll sum = 0;
	while(x){
		sum += table[x];
		x -= x&-x;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	ll n , k , x; cin >> n >> k;
	map<ll , ll> cord;
	cord[0];
	for(int i = 1;i <= n ;i++){
		cin >> x;
		x -= k;
		A[i] = A[i-1] + x;
		cord[A[i]];
	}
	int id = 1;
	for(auto it : cord)
		cord[it.F] = id++;

	for(int i = 0;i <= n ; i++)
		A[i] = cord[A[i]];

	ll ans = 0;
	for(int i = 0;i <= n ;i++){
		ans += query(A[i]);
		upt(A[i] , 1);
	}
	cout << ans << endl;

	return 0;
}







