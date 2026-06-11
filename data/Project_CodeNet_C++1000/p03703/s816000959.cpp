#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<
pair<long long, long long>,
null_type,
less< pair<long long, long long> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
#define pl cout<<endl;
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); }
const long long INFll=1ll*INF*INF;
const long double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define sz(a) int((a).size())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long genrand(long long L,long long R)
{
	return uniform_int_distribution<long long>(L, R)(rng);
}
//use brackets before operations if taking MOD
//use map only when necessary
//give long long to arrays and variables properly
int mul(int a, int b,int mod = MOD) {
	return int(a * 1ll * b % mod);
}
int norm(int a,int mod = MOD) {
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
	//a = (a%mod+mod)%mod;
	return a;
}
int powmod(int x,int y,int mod = MOD){
	int res = 1;
	while(y>0)
	{
		if(y&1)
			res = mul(res,x,mod);
		x = mul(x,x,mod);
		y=y>>1;
	}
	return res;
}
int inv(int a,int mod = MOD) {
	return powmod(a, mod - 2);
}
int main() {
	fast();

	long long n, k; cin>>n>>k;
	vector<long long> a(n+1, 0);
	ordered_set s;
	long long ans = 0, sum = 0;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		sum += a[i];
		a[i] = sum - i*k;
		// cout<<a[i]<<' ';
	}
	// pl;

	s.insert({0,0});
	for(int i = 1;i<=n;i++){
		ans += s.order_of_key({a[i]+1, -INF});
		s.insert({a[i], i});
	}
	
	cout<<ans<<endl;

	return 0;
}