#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define assign(x,val) memset(x,val,sizeof(x))
#define motherfucker  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define for0(i,n) for(ll i=0;i<n;++i)
#define for1(i,n) for(ll i=1;i<=n;++i)
#define ford(i,n) for(ll i=n;i>=1;--i)
#define forg(i,a,b) for(ll i=a;i<b;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpl;
long long mod = 1000000007;
const long double PI = (long double)(3.1415926535897932384626433832795);
 
 
void solve(){
	int n;cin>>n;
	vpi arr(n);
	for0(i,n){
		cin>>arr[i].ff;
		arr[i].ss = i;
	}
	sort(all(arr));
	int cnt = 0;
	for0(i,n){
		if(arr[i].ss%2!=i%2){
			cnt++;
		}
	}
	cout<<cnt/2<<endl;
}
 
int main(){
	motherfucker
	ll t = 1;
	//cin>>t;
	for0(i, t){
		solve();
	}
	return 0;
}