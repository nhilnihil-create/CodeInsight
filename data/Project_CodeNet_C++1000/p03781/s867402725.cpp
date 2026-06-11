#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin >> x;
	int d = sqrt(2 * x + 0.25) - 0.5;
	int r = (d + 2) * (d + 1) / 2 - x;
	if(x - d * (d + 1) / 2 == 0) cout << d << '\n';
	else cout << d + 1 << '\n';
}