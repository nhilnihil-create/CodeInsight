#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
ll  n, m;

int main(){
	ll x;
	cin >> n >> m >> x;
	ll ans = floor((long double)(m/x));
	ans -= floor((long double)(n-1LL)/x);
	cout << ans;
}
