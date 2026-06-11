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
	return b ? gcd(b, a % b) : a;
}
template<typename T>
T lcm(T a, T b) {
	return a * b / gcd(a, b);
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
ll frac(ll n)
{
	if (n == 0) {
		return 1;
	}
	return (n * frac(n - 1)) % MOD;
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
int main() {
	ll N, M;cin >> N >> M;
	ll ans = 0;
	if      (N >= M/2) ans =M / 2;
	else if (N <= M / 2) {
			ans += N;
			M -= N*2;
			ans += M / 4;
		}
	cout << ans;
}