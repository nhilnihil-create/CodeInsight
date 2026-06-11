#include <bits/stdc++.h>

using namespace std;

void maxi(int &a, int b) {
	a = max(a,b);
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	int x;
	cin >> x;
	int k=0;
	int t=0;
	while (k < x) {
		t+=1;
		k+=t;	
	}
	cout << t << "\n";
}

