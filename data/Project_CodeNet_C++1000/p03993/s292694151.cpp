#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll a[100005];
ll inf = 1000000000;
int main() {
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll count = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[a[i] - 1] == i + 1) {
			a[a[i] - 1] = 0;
			count++;
		}
		
	}
	cout << count << endl;
	return 0;
}