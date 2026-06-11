#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(ll a, ll b){
	if(a == b) return a;
	if(a < b){
		long long take = (b - 1) / a;
		return 2 * a * take + f(b - take * a, a);
	} else {
		long long take = (a  - 1) / b;
		return 2 * b * take + f(a - take * b, b);
	}
}
int main(){
	long long n, x; cin >> n >> x;
	cout << f(x, n - x) + n << endl;
	return 0;
}
