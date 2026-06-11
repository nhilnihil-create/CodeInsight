#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, p = 0, lst = 1;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	for(auto i : a) {
		if(lst == 0) lst = 1;
		else lst = (i-p)&1;
		if(p && n-- == 1) return cout << (lst ?"First":"Second"), 0;
		else if(n <= i-p) return cout << ((n%2!=(i-p)%2)?"First":"Second"), 0;
		n -= i-p;
		if(i != p) lst = 0;
		p = i;
	}
}
