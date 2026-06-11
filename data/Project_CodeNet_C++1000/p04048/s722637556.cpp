#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll work(ll a, ll b) {
	if (a > b) swap(a, b);
	if (!(b % a)) return 2 * b - a;
	ll ns = b / a;
	return ns * (2 * a) + work(b % a, a);
} 
int main() {
	ll n, x;
	cin >> n >> x;
	cout << (n + work(x, n - x)) << endl;
	return 0;
}
