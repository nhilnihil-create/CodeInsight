#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int N = 2000 + 5;
ll a[N],b[N];

int main(){
	int n;
	ll x;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		scanf("%lld",&a[i]);
		b[i] = a[i];
	}
	ll sum = INF;
	for(int i = 0; i < n; i++){
		ll ans = 0;
		for(int j = 0; j < n; j++){
			b[j] = min(b[j],a[(j-i+n)%n]);
			ans += b[j];
		}
		sum = min(sum,ans + i*x);
	}
	cout << sum << endl;
	return 0;
}
