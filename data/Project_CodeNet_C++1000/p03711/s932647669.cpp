#include <bits/stdc++.h>
#define Y "Yes"
#define N "No"
using namespace std;

int x, y;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[13];
	a[1] = 1;
	a[3] = 1;
	a[5] = 1;
	a[7] = 1;
	a[8] = 1;
	a[10] = 1;
	a[12] = 1;
	a[4] = 2;
	a[6] = 2;
	a[9] = 2;
	a[11] = 2;
	a[2] = 3;
	cin >> x >> y;
	if (a[x] == a[y]) cout << Y;
	else cout << N;
}