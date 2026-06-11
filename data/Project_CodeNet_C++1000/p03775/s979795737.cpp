#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
const int MxN = 10005 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
# define RFOR(i,a,b) for(int i = a ; i >= b ; --i)

/* VARIABLES */
ll n ; 
/* END OF VARIABLES */

int dig(ll n) {
	int ans = 0 ;
	while(n) {
		n = n / 10 ; 
		ans++;
	}
	return ans ; 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	int ans = 1e9 ; 
	cin >> n ; 
	for(ll i = 1 ; i <= sqrt(n) ; i++) {
		if(n%i == 0) 
			ans = min(ans,dig(max(i,n/i))) ; 
	} 
	cout << ans ; 
	return 0 ; 
}

