#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
 
void faster(){
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);
}
 
const int MAXN = 2e5 + 1;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
 
ll n, x;

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
 
faster();

cin >> n >> x;

cout << 3ll * (n - gcd(n, x));


return 0;
}