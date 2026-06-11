#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	char str[100]; cin >> str;
	cout << (strncmp(str, "YAKI", 4) ? "No" : "Yes") << "\n";
	
	return 0;
}
