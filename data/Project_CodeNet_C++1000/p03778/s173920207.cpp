#include<bits/stdc++.h>

using namespace std;


int main() {
	int w, a, b;
	cin >> w >> a >> b;
	int mx, mn; 
	mx = max(a, b);
	mn = min(a, b);
	if(mx-(mn+w) <= 0)
		cout << 0;
	else 
		cout << mx-(mn+w);
	return 0;
}
