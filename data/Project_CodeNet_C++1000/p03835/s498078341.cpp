#include<bits/stdc++.h>
using namespace std;

int x,y,z;

int main() {
	cin >> x >> y;
	for (int i = 0; i <= x; i++) {
		int tmp = y-i;
		if (tmp >= 0) {
			z += max(0, min(tmp+1, x-(tmp-x)+1));
		}
	}
	cout << z << "\n";
}