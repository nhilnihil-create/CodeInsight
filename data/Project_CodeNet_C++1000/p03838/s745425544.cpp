#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 2020, mod = 924844033;
int get(int a, int b) {
	return abs(a-b) + (a>b)*2;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	cout << min({get(a, b), get(a, -b)+1, get(-a, b)+1, get(-a, -b)+2});
}
