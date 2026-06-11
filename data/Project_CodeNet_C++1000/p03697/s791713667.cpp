#include <bits/stdc++.h>
using namespace std;
 
int a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	int x = a + b;
	if (x < 10) cout << x;
	else cout << "error";
}