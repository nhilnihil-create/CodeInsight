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

int main() {

	ll();
	
	int a, b;
	cin >> a >> b;
	if (a > b && b != 1)
		cout << "Alice" << endl;
	else if (b > a && a != 1)
		cout << "Bob" << endl;
	else if (a == 1&&b!=1)
		cout << "Alice" << endl;
	else if (b == 1&&a!=1)
		cout << "Bob" << endl;
	else if (a==b)
		cout << "Draw"<<endl;
	
}