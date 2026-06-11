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
	 
	int a, b, c;
	cin >> a >> b >> c;
	if ((a != b&&a==c)||(a==b&&a!=c)||(b==c&&c!=a))
		cout << 2 << endl;
	else if (a != b&&a != c&&b != c)
		cout << 3 << endl;
	else if (a == b&&a == c)
		cout << 1 << endl;
	

}



