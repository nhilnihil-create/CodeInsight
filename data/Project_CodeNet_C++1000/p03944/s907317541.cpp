#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l, b, n;
	cin >> l >> b >> n;
	int e_top = 0, e_bottom = 0, e_left = 0, e_right = 0;
  	// eliminating length of top, bottom, left, right.
	
	for(int i = 0; i < n; i++) {
		int x, y, a;
		cin >> x >> y >> a;
		if(a == 1) {
			e_left = max(e_left, x);
		} else if(a == 2) {
			e_right = max(e_right, l - x);
		} else if(a == 3) {
			e_bottom = max(e_bottom, y);
		} else {
			e_top = max(e_top, b - y);
		}
	}
	
	l = max(0, l - e_left - e_right);
	b = max(0, b - e_top - e_bottom);
	
	cout << l * b;
}
