#include<bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define all(x) x.begin(),x.end()
#define puts(x) cout << x << "\n"
using namespace std;
int input() { int r; cin >> r; return r; }
vector<int>v[123456]; int n;
int f(int i) {
	vector<int>v1;
	for (int t : v[i])v1.push_back(f(t));
	sort(all(v1), greater<int>());
	int r = 0;
	for0(j, v1.size())r = max(r, v1[j] + j+1);
	return r;
}
signed main() {
	n = input(); for1(i, n)if (i != 1)v[input()].push_back(i); puts(f(1));
}