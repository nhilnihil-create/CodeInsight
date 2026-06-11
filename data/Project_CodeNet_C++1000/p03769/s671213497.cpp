#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define REP(i,n) for(int i=0; i < (n); ++i)
#define SIZE(c) (int) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define PI 3.14159265358979311600
#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef vector < int > VI;
typedef vector<ll> VL;

typedef long double K;

int cur = 1;

deque<int> go(long long n) {
	deque<int> result;
	if (n == 0) {
		return result;
	}
	if (n % 2) {
		result = go(n / 2);
		result.insert(result.begin() + SIZE(result)/2, cur);
		result.push_back(cur);
		++cur;
		return result;
	}
	result = go(n - 1);
	result.push_front(cur);
	result.push_back(cur);
	++cur;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;

	auto result = go(n);

	cout << (int)result.size() << '\n';

	for (auto& item : result) {
		cout << item << ' ';
	}
	cout << endl;

	return 0;
}