#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
ull x, y;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> x >> y;
	if(x > y) swap(x, y);
	cout << (y - x <= 1 ? "Brown" : "Alice") << "\n";
}