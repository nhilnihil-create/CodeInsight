#include <bits/stdc++.h>
using namespace std;

int a, c;
char b;

int main () {
	cin >> a >> b >> c;
	if ((int)b == 43){
		cout << a + c;
	} else if ((int)b == 45){
		cout << a - c;
	}
}