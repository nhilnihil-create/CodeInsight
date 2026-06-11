#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>

using namespace std;


int main() {
	map<int, int> mp;

	long long int a, b, c, d, e, f, g,result;
	
	cin >>a>>b>>c>>d>>e>>f>>g;

	result = b;

	if (a % 2 == d % 2 && d % 2 == e % 2) { result += a + d + e; }
	else {
		result += a + d + e-1;
		if (a == 0 || d == 0 || e == 0) { result = b + a / 2 + d / 2 + e / 2; }
	}
	cout << result;
}