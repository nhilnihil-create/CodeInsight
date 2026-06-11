#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 998244353;
const ll INF = 1e18;
const ll MAXN = 1e6+10;

ll N;
deque<ll> F,S;
ll c = 1;

void solve(ll x){
	// cout<<"Do "<<x<<'\n';
	if (x<=0)return;
	if (x%2==0){
		// Basically u wanna minus
		solve(x-1);
		F.push_front(c);
		S.pb(c);
		++c;
	}else{
		solve((x-1)/2);
		S.push_front(c);F.push_front(c);++c;
	}

}

int main(){
	cin>>N;
	solve(N);
	cout<<SZ(F)*2<<'\n';
	for (auto i : F)cout<<i<<' ';
	for (auto i : S)cout<<i<<' ';
}