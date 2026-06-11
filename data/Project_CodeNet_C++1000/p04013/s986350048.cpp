#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nrep(i,a,b) for(int i=int(a);i>=int(b);--i)
#define trv(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout<<"\n"<<#x<<" is "<<x<<"\n"
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ZERO(box) memset(box, 0, sizeof(box));
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define chkbit(s, b) (s & (1<<b))
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod=1e9+7;

ll sq(ll a){ return a*a;}

void solve(){
	int n,A;
	cin>>n>>A;
	vi x(n+1,0);
	vvi dp(51,vi(2501,0));
	
	dp[0][0]=1;
	rep(i,1,n){
		cin>>x[i];
	}
	// dp[i][j] denotes the number of ways to achive sum j, using i cards;
	ll tot=0;
	rep(i,1,n){
		nrep(posi,i-1,0){
			rep(j,0,tot){
				dp[posi+1][j+x[i]] += dp[posi][j];
			}
		}
		tot += x[i];
	}
	ll ways=0;
	rep(i,1,n){
		ways += dp[i][A*i];
	}
	cout<<ways<<"\n";
	
}


int main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();	
	}	
}
/*input
4 8
7 9 8 9
*/