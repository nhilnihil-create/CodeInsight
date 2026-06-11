#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>

using ll = long long;
typedef unsigned long long ull;
typedef std::pair<ll, ll>P;

ll min(ll a, ll b) {
	if (a >= b)return b;
	else return a;
}
ll max(ll a, ll b) {
	if (a >= b)return a;
	else return b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

const ll Z = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
bool flag = true;
bool fl = true;
bool f = true;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
std::string abc = "abcdefghijklmnopqrstuvwxyz";
struct edge { ll to, cost; };
std::vector<edge>V[100010], W[100010];
typedef std::vector<std::vector<int>>ma;

int main() {
	ll n, r[5010];
	std::cin >> n;
	r[1] = 1;
	for (int i = 2;i <= 5000;i++)r[i] = r[i - 1] + i;
	for (int i = 5000;i >= 1;i--) {
		if (r[i] < n) {
			std::cout << i + 1 << std::endl;
			n -= i + 1;
		}
		if (n == 1) {
			std::cout << 1 << std::endl;
			break;
		}
	}
}