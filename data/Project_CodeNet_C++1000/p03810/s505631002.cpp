#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;

bool solve(vector <int> a) {
	ll tmp = 0,tmp1 = 0;
	for (int u : a){
		if (u % 2)
			tmp1++;
		else
			tmp++;
	}
	if (tmp % 2)
		return 1;
	if (tmp1 != 1)
		return 0;
	for (int i = 0; i < n;i++){
		if (a[i] % 2)
			a[i]--;
		if (a[i] == 0)
			return 0;
	}
	ll w = 0;
	for (int u : a)
		w = gcd(w,u);
	for (int i = 0; i < n; i++)
		a[i] /= w;
	return 1 - solve(a);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	vector <int> a;
	for (ll i = 0, x; i < n; i++){
		cin >> x;
		a.push_back(x);
	}
	bool ans = solve(a);
	if (ans)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}