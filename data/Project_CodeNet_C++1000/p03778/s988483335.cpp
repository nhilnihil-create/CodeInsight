#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int w, a, b;
	cin >> w >> a >> b;
	if (a > b) {
		swap(a,b);
	}
	cout << max(0,b - (a + w));
}

















