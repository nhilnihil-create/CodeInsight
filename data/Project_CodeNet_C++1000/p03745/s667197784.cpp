#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	
	
	int state = 0;	// 0:both, 1:<=, 2:>=
	ll ans = 1;
	for(int i = 0; i < n-1; ++i){
		switch(state){
		case 0:
			if(a[i] < a[i+1]){
				state = 1;
			}
			else if(a[i] > a[i+1]){
				state = 2;
			}
			else{
				state = 0;
			}
			break;
		case 1:
			if(a[i] > a[i+1]){
				ans++;
				state = 0;
			}
			break;
		case 2:
			if(a[i] < a[i+1]){
				ans++;
				state = 0;
			}
			break;
		default:
			break;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

