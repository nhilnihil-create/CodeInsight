// ABC_054_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int a, b;
	cin >> a >> b;

	if(a == 1 && b != 1) cout << "Alice" << "\n";
	else if(a != 1 && b == 1) cout << "Bob" << "\n";
	else if(a > b) cout << "Alice" << "\n";
	else if(a < b) cout << "Bob" << "\n";
	else cout << "Draw" << "\n";

	return 0;
}