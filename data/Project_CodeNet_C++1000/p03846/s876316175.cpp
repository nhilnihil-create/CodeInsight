#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<list>
#include<numeric>
typedef long long ll;

#define pi 3.14159265358979323846
#define VI vector<int>
#define VLL vector<long long>
#define MAX max_element
#define MIN min_element
#define all(v) v.begin(), v.end()
const ll MOD = 1e9 + 7;
using namespace std;
template<typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
	//return b ? gcd(b, a % b) : a;
}
template<typename T>
T lcm(T a, T b) {
	ll g = gcd(a, b);
	return a / g * b; // Be careful not to overflow
	//return a * b / gcd(a, b);
}

template<typename T>
T binarysearch(vector<T> A, T key) {
	ll left = 0;ll right = 4;ll mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (key == A[mid]) return 1;
		if (key > A[mid]) left = mid + 1;
		else if (key < A[mid]) right = mid;
	}
	return 0;
}

template<typename T>
T finder(vector<T> vec, T number) {
	auto itr = find(vec.begin(), vec.end(), number);
	size_t index = distance(vec.begin(), itr);
	if (index != vec.size()) { // 発見できたとき
		return 1;
	}
	else { // 発見できなかったとき
		return 0;
	}
}
ll frac(ll n)//階乗
{
	if (n == 0) {
		return 1;
	}
	return (n * frac(n - 1)) % MOD;
}

template<typename T>
T keta(T a) {
	ll kazu = 1;
	while (1) {
		if (a / 10 != 0) { a /= 10;kazu++; }
		else break;
	}
	return kazu;
}//桁数


template<typename T>
T nCr(ll n, T r) {
	ll ans = 1;
	for (int i = n; i > n - r; --i) {
		ans = ans * i;
	}
	for (int i = 1; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}
/*char r[4];
int yaju[4];
char op[3];
int sum = 0;
scanf("%s", r);
for (int i = 0;i < 4;i++) {
	yaju[i] = r[i] - '0';
}
*/
//vector<vector<int>> data(3, vector<int>(4));

int main() {
	ll mod = 1e9 + 7;
	ll ans = 1;
	ll N;cin >> N;
	vector<ll>A(N + 1);
	vector<ll>sum(N + 1);
	A[0] = 9999999999999;
	for (ll i = 1;i <= N;i++)cin >> A[i];
	sort(all(A));
	for (ll i = 0;i < N;i++) {
		sum[A[i]]++;
	}
	if (N % 2 != 0) {
		for (ll i = 0;i < N;i += 2) {
			if (sum[i] <= 2)ans *= sum[i];
			else ans *= 0;
			ans %= mod;
		}
		if (sum[0] >= 2)ans *= 0;
	}
	if (N % 2 == 0) {
		for (ll i = 1;i < N;i += 2) {
			if (sum[0] != 0)ans *= 0;
			if (sum[i] <= 2)ans *= sum[i];
			else ans *= 0;
			ans %= mod;
		}
	}
	cout << ans << endl;
}