// " In the Name of God, the Beneficent, the Merciful "
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
bool isOk;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}				
	sort(a, a + n);
}

void check1() {
	int t = a[0];
	if (t == n - 1 || 2 * t <= n)
		isOk = true;	
}

void check2() {
	int minn = a[0], maxx = a[n - 1];
	
	if (maxx - minn > 1) {
		cout << "No";
		exit(0);
	}
	
	int cmax = 0, cmin = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == maxx)
			cmax++;
		else
			cmin++;	
	}
	
	if ((2 * (maxx - cmin)) <= cmax && maxx - cmin > 0)
		isOk = true;
	
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	
	input();
	if (a[n - 1] == a[0])
		check1();
	else
		check2();	
	
	if(isOk)
		cout << "Yes";
	else
		cout << "No";	
		
	
	return 0;
}
