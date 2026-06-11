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

const ll INF = 1e16 + 7;
const int N  = 1e5 + 7;

ll H[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n , a , b ;
	cin >> n >> a >> b ;
	for(int i = 1;i <= n ;i++)
		cin >> H[i];

	sort(H+1 , H+n+1);
	
	ll l = 1 , r = INF , ans = INF , mid;

	while(l <= r){


		mid = (l+r)>>1;

		bool ok = true;

		ll left = mid;
		for(int i = n ;i >= 1; i--){

			// overflow
			if(b >= (H[i] + mid-1)/mid)
				continue;

			ll req = (H[i] - mid*b + (a-b-1))/(a-b);


			if(req > left){
				ok = false;
				break;
			}

			left -= req;
		}
		if(left < 0)
			ok = false;

		if(ok){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	cout << ans << '\n';



	return 0;
}
