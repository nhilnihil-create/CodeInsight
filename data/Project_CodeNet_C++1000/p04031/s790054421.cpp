#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define deb(x) cout<<#x<<" "<<x<<'\n';
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};



int main(){
    	
	ll n;
	scanf("%lld\n",&n);
	vector<ll> a(n);
	for(ll i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}

	ll ans = INT_MAX;
	for(ll i=-100;i<=100;++i){
		ll sum=0;
		for(ll j=0;j<n;++j){
			sum+= (a[j]-i)*(a[j]-i);
		}
		ans=min(ans,sum);	
	}

	ans==INT_MAX?printf("0\n"):printf("%lld\n",ans);


	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}
