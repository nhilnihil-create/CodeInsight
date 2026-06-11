#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <complex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>

#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
#define int ll

using namespace std;
typedef long long ll;
typedef long double ld;


signed main() {
	#ifdef PC
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif	


	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	vector<int> a(n);
	a[0] = 30000;
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1] + 30000;
	}	
	auto b = a;
	reverse(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		a[p[i]] += i;
	}
	for (auto x : a)
		cout << x << " ";
	cout << endl;
	for (auto x : b) 
		cout << x << " ";
	cout << endl;
	return 0;
}