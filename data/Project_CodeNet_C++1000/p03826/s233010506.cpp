#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}
const int N = 1e3 + 3;
int main() {

	ll();
	
	int a, b, c, d,r1,r2;
	cin >> a >> b >> c >> d;
	r1 = a*b;
	r2 = c*d;
	if (r1 > r2)
		cout << r1 << endl;
	else
		cout << r2 << endl;
}