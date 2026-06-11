#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
	int a, b;
	cin >> a >> b;

	if (a <= 0 && 0 <= b) cout << "Zero" << endl;
	else if (a > 0) cout << "Positive" << endl;
	else if ((b-a)%2==1) cout << "Positive" << endl; 
	else cout << "Negative" << endl;
}