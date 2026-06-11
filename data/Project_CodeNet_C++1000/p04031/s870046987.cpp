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
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod=1e9+7;

ll sq(ll a){ return a*a;}

void solve(){
	int n;cin>>n;
	vi a(n);
	double sum=0;
	rep(i,0,n-1) cin>>a[i],sum+=a[i];
	sum = sum/double(n);
	sum = round(sum);
	ll cost=0;
	rep(i,0,n-1){
		cost += sq(sum-a[i]);
	}
	cout<<cost;
	
}


int main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();	
	}	
}
/*input
3
4 2 5
*/