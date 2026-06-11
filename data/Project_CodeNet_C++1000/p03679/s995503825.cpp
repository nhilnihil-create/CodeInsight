#pragma GCC optimize ("03")
#pragma GCC target("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define nl "\n"
 
const int mod=10e7+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x, a, b ;
	cin >> x >> a >> b;
	int eat=-a+b;
	//fifth day after it was expired
	int ex=-a+x;
	//expires on the -4th day
	if(eat<=0) {
		cout << "delicious";
	}else if(eat<=x) {
		cout << "safe";
	}else {
		cout << "dangerous";
	}
}
