#include<iostream>
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

int main() {

	ll();
	
	int a, b, sum = 0;
	cin >> a >> b;
	sum = a + b;
	if (sum >= 24)
		cout << (a + b) - 24 << endl;
	else
		cout << (a + b)<<endl;
}