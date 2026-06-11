#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
	cin >> N;
	for(int i = 1; ; i++) {
		int z = i * (i + 1) / 2;
		if(N <= z) {
			int q = z - N;
			for(int j = 1; j <= i; j++) {
				if(j != q) cout << j << endl;
			}
			break;
		}
	}
	return 0;
}