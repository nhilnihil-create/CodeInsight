#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while(b){
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

bool canWin(vector<int> dat) {
	sort(dat.begin(), dat.end());
	int n = dat.size();
	if (n == 1) return false;
	if (n == 2) return dat[0] != dat[1];
	int parity = 0;
	for (int i = 0; i < n; i++) {
		parity ^= (dat[i] - 1)%2;
	}
	if (parity) {
		return true;
	}
	if (dat[0] == 1) {
		return false;
	}
	int ocnt = 0;
	for (int i = 0; i < n; i++){
		if (dat[i]%2) {
			ocnt++;
		}
	}
	if (ocnt >= 2) return false;
	for (int i = 0; i < n; i++) {
		if (dat[i]%2) {
			dat[i]--;
			int totgcd = dat[0];
			for (int j = 0; j < n; j++) {
				totgcd = gcd(totgcd, dat[j]);
			}
			for (int j = 0; j < n; j++){
				dat[j] /= totgcd;
			}

			return !canWin(dat);
		}
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> dat(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &dat[i]);
	}
	if (canWin(dat)) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	return 0;
}
